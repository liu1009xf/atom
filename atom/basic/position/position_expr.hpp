#ifndef ATOM_BASIC_POSITION_POSITION_EXPR
#define ATOM_BASIC_POSITION_POSITION_EXPR

#include <boost/preprocessor.hpp>
#include <type_traits>

namespace atom::detail{

#define ATOM_CLASSNAME position
#include "atom/basic/base/crtp_base.ipp"
}

#endif /* ATOM_BASIC_POSITION_POSITION_EXPR */
