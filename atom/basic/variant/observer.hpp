#ifndef ATOM_BASIC_BASE_OBSERVER_HPP
#define ATOM_BASIC_BASE_OBSERVER_HPP

#include <variant>
#include "atom/agent/trader/trader.hpp"

namespace atom::base {

    // FeedObservers
    using feed_observer = std::variant<std::monostate, atom::agent::Trader>;

    
    template<typename E>
    struct notify_feed
    {
    public:
        notify_feed(const E& event) :event_(event) {};
        
        template<typename T>
        void operator()(const T&) { std::cout << "not implemented\n"; }
        void operator()(const atom::agent::Trader& trader) { trader.process(event_); };
    private:
        const E& event_;
    };
}


#endif //!ATOM_BASIC_BASE_OBSERVER_HPP