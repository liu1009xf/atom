#ifndef ATOM_TYPE_TRAITS_HPP
#define ATOM_TYPE_TRAITS_HPP

#include <type_traits>

#include "atom/traits/optional.hpp"
#include "atom/traits/container.hpp"

namespace atom::traits
{
    template<typename T, typename V>
    using is_optional_of = detail::is_optional_of<T, V>;

    template<typename T, typename V>
    constexpr auto is_optional_of_v = detail::is_optional_of<T, V>::value;


    template<typename C, typename V>
    using contains = detail::contains<C, V>;
} // namespace atom::type_traits


#endif //!ATOM_TYPE_TRAITS_HPP