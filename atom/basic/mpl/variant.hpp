#ifndef ATOM_BASIC_MPL_VARIANT_HPP
#define ATOM_BASIC_MPL_VARIANT_HPP

#include <variant>
#include <type_traits>

namespace atom::mpl
{
    // Check if Variant can hold
    template <class T, class U> struct can_hold;

    template <class T, class... Ts>
    struct can_hold<T, std::variant<Ts...>>
        : std::bool_constant<(std::is_same_v<T, Ts> || ...)>
    { };

    //append new type to variant
    namespace detail {
        template <class V, class T> struct variant_append_helper;

        template <class... A, class T>
        struct variant_append_helper<std::variant<A...>, T> {
            using type = std::conditional_t < std::disjunction_v<std::is_same<T, A>...>,
                std::variant<A...>,
                std::variant<A..., T>
            >;
        };
    }

    template <class V, class T>
    using variant_append = typename detail::variant_append_helper<V, T>::type;

    //variant cast to a new variant type
    namespace detail {
        template <class... Args>
        struct variant_cast_proxy
        {
            std::variant<Args...> v;

            template <class... ToArgs>
            operator std::variant<ToArgs...>() const
            {
                return std::visit([](auto&& arg) -> std::variant<ToArgs...> { return arg; },
                    v);
            }
        };
    }
    
    template <class... Args>
    detail::variant_cast_proxy<Args...> variant_cast(const std::variant<Args...>& v)
    {
        return { v };
    }

} // namespace atom::mpl

#endif //!ATOM_BASIC_MPL_VARIANT_HPP
