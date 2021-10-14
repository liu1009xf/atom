#ifndef ATOM_ENGINE_FEED_ENGINE_HPP
#define ATOM_ENGINE_FEED_ENGINE_HPP

#include <vector>

#include "atom/basic/variant/observer.hpp"
#include "atom/event/event_expr.hpp"
#include "atom/basic/variant/contract.hpp"

namespace atom::engine::detail
{
    class FeedEngine
    {
    private:
        using Contract = atom::variant::contract;
        using Observer = base::feed_observer;
        using Observers = std::vector<Observer>;
    public:
        FeedEngine() = default;
        FeedEngine(Contract contract) : contract_(contract) {}//instantiate feed engine with some data needed
        FeedEngine(Contract contract, 
            Observers observers) : contract_(contract), observers_(observers) {}
        
        void addObserver(const Observer& fo) {
            observers_.push_back(fo);
        }

        template<typename E,
            std::enable_if_t<atom::event::detail::is_event_v<E>, std::nullptr_t> = nullptr
        >//is event
        void notify(const E& event) const {
            base::notify_feed<E> nf(event);
            for (const auto& o : observers_) {
                std::visit(nf, o);
            }
        }

    private:
        Observers observers_;
        Contract contract_;
    };
} // namespace atom::engine::detail


#endif //!ATOM_ENGINE_FEED_ENGINE_HPP