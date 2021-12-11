#ifndef ATOM_BASIC_OPERATOR
#define ATOM_BASIC_OPERATOR

#include "operator/combine.hpp"
#include "operator/equal.hpp"

namespace atom::op {
    // template <typename T, typename S>
    // using combinable = detail::combinable<T, S>;

    template <typename T, typename S>
    using equals = detail::equals<T, S>;
}

#endif /* ATOM_BASIC_OPERATOR */
