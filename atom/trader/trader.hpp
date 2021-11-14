#ifndef ATOM_AGENT_TRADER_TRADER_HPP
#define ATOM_AGENT_TRADER_TRADER_HPP

#include <optional>

#include "atom/basic/validator/trival.hpp"
#include "atom/basic/authoriser/trival.hpp"
#include "atom/basic/visitor/event_notify.hpp"
#include "atom/basic.hpp"

namespace atom::detail
{
    template<typename S>
    class Trader_ {
    public:

        Trader_(const S& strategy) :strategy_(strategy) {};

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

    template<typename S, typename C,
        typename OO, typename LP, typename AF
    >
    class Trader {
    public:
        Trader(const S& strategy);
        Trader(const S& strategy, const C& baseCurrency);
        
        template<typename T>
        void process(T&& event) const;

        // template<typename O,
        //     std::enable_if_t<
        //     std::is_convertible_v<O, OO>,
        //     std::nullptr_t
        //     > = nullptr
        // >
        void addOrderObserver(const OO& observer) const;

    private:
        S strategy_;
        C baseCurrency_;
        std::optional<LP> tradingLimitation_;
        std::optional<AF> authorisationFlow_;
        std::vector<OO> orderObservers_;
    };
    #include "impl/trader.ipp"
} // namespace atom::detail

#endif //!ATOM_AGENT_TRADER_TRADER_HPP
