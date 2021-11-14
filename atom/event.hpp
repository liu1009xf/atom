#ifndef ATOM_EVENT_HPP
#define ATOM_EVENT_HPP

#include "atom/basic/event/event_expr.hpp"

#include "atom/basic/event/tick_event.hpp"

namespace atom
{
    template<typename T>
    using TickEvent = atom::event::detail::TickEvent<T>;
    
} // namespace name

#endif //!ATOM_COMPONENT_EVENT_HPPs