#ifndef ATOM_BASIC_TRAITS_OPTIONAL_HPP
#define ATOM_BASIC_TRAITS_OPTIONAL_HPP


namespace atom::traits::detail {
    template <typename T, typename V>
    struct is_optional_of {
        static constexpr bool value =
            std::is_convertible_v<T, std::optional<V>>;
    };
}


#endif //!atom/basic/traits/optional.hpp