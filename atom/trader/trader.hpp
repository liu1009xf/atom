#ifndef ATOM_AGENT_TRADER_TRADER_HPP
#define ATOM_AGENT_TRADER_TRADER_HPP

#include "atom/event/operator.hpp"
#include "atom/validator/trival.hpp"
#include "atom/authoriser/trival.hpp"
#include "atom/basic/visitor/event_notify.hpp"

namespace atom::agent
{
    template<typename S>
    class Trader {
    public:

        Trader(const S& strategy) :strategy_(strategy) {};

        template<typename T>
        void process(T&& event) const
        {
            strategy_.actOn(std::forward<T>(event));
        }

        auto _strategy() const
        {
            return strategy_;
        }            
    private:
        S strategy_;
    };

    template<typename S, typename LP, typename AF, typename OO>
    class Trader_{
    public:

        Trader_(const S& strategy) :strategy_(strategy) {};
        
        template<typename T>
        void process(T&& event) const
        {
            auto raw_signal = strategy_.actOn(std::forward<T>(event));

            auto validatedSignal = tradingLimitation_.value_or(atom::detail::TrivialValidator())
                .validate(raw_signal);
            auto authorisedSignal = validatedSignal.available() ?
                authorisationFlow_.value_or(atom::detail::TrivialAuthoriser())
                .authoise(std::move(validatedSignal)) : raw_signal;

            if(authorisedSignal.available()) {
                auto on = atom::visitor::EventNotifyVisitor(authorisedSignal);
                for (const auto& oo : orderObservers_) {
                    std::visit(on, oo);
                }
            }
        }

        template<typename O,
            std::enable_if_t<
                std::is_convertible_v<O, OO>,
                std::nullptr_t
            > = nullptr
        >
        void addOrderObserver(O&& observer) const {
            orderObservers_.push_back(observer);
        }

    private:
        S strategy_;
        std::optional<LP> tradingLimitation_;
        std::optional<AF> authorisationFlow_;
        std::vector<OO> orderObservers_;
    };
} // namespace atom::agent

#endif //!ATOM_AGENT_TRADER_TRADER_HPP
