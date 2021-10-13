#ifndef ATOM_BASIC_HPP
#define ATOM_BASIC_HPP

#include <optional>
#include <type_traits>

#include "atom/type_traits.hpp"

#include "atom/basic/container/quote.hpp"

namespace atom {
    template <typename V = double, typename Q = unsigned long int>
    using OneSideQuote = basic::detail::OneSideQuote<V, Q>;
    template <typename V>
    using Quote = basic::detail::Quote<V>;
}
#endif //!ATOM_BASIC_HPP