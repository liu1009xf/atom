#ifndef ATOM_BASIC_BASE_OBSERVER_HPP
#define ATOM_BASIC_BASE_OBSERVER_HPP

#include <variant>
#include "atom/trader/trader.hpp"

namespace atom::base {

    // FeedObservers
    using feed_observer = std::variant<std::monostate>;

    
    template<typename E>
    struct notify_feed
    {
    public:
        notify_feed(const E& event) :event_(event) {};
        
        template<typename T>
        void operator()(const T&) { std::cout << "not implemented\n"; }
        template<typename T>
        void operator()(const atom::agent::Trader<T>& trader) { trader.process(event_); };
    private:
        const E& event_;
    };

    using rfq_observer = std::variant<std::monostate>;
}


#endif //!ATOM_BASIC_BASE_OBSERVER_HPP