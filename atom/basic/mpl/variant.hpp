#ifndef ATOM_BASIC_MPL_VARIANT_HPP
#define ATOM_BASIC_MPL_VARIANT_HPP

namespace atom::mpl
{
    template <class T, class U> struct can_hold;

    template <class T, class... Ts>
    struct can_hold<T, std::variant<Ts...>>
        : std::bool_constant<(std::is_same_v<T, Ts> || ...)>
    { };
    
} // namespace atom::mpl

#endif //!ATOM_BASIC_MPL_VARIANT_HPP
