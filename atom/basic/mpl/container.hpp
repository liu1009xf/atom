#ifndef ATOM_BASIC_MPL_CONTAINER_HPP
#define ATOM_BASIC_MPL_CONTAINER_HPP
#include <vector>

namespace atom::mpl
{
    template<typename C, typename V>
    struct replace_value_type {};

    template<typename C, typename V>
    struct replace_value_type<std::vector<C>, V> {
        using type = std::vector<V>;
    };
}

#endif //!ATOM_BASIC_MPL_CONTAINER_HPP