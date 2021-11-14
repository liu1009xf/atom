#ifndef ATOM_EVENT_EVENT_EXPR_HPP
#define ATOM_EVENT_EVENT_EXPR_HPP

// #include <string>
#include <boost/preprocessor.hpp>
#include <type_traits>

namespace atom::event::detail {

#define ATOM_CLASSNAME event
#include "atom/basic/base/crtp_base.ipp"
}
#endif // !ATOM_EVENT_EVENT_EXPR_HPP
