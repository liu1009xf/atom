#ifndef ATOM_EVENT_TICK_EVENT_HPP
#define ATOM_EVENT_TICK_EVENT_HPP

#include "atom/event/event_expr.hpp"

namespace atom::event::detail {

    class TickEvent: public event<TickEvent>
    {
    public:
        auto show() const {
            return 11111111;
        }
    };

}
#endif //!ATOM_EVENT_TICK_EVENT_HPP