#ifndef ATOM_BASIC_MPL_VARIANT_HPP
#define ATOM_BASIC_MPL_VARIANT_HPP

#include <variant>
#include <type_traits>

namespace atom::mpl
{
    template <class T, class U> struct can_hold;

    template <class T, class... Ts>
    struct can_hold<T, std::variant<Ts...>>
        : std::bool_constant<(std::is_same_v<T, Ts> || ...)>
    { };

    namespace detail{
        template <class V, class T> struct variant_append_helper;

        template <class... A, class T>
        struct variant_append_helper<std::variant<A...>, T> {
            using type = std::variant<A..., T>;
        };
    }

    template <class V, class T>
    using variant_append = typename detail::variant_append_helper<V, T>::type;

} // namespace atom::mpl

#endif //!ATOM_BASIC_MPL_VARIANT_HPP
