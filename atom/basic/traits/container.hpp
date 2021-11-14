#ifndef ATOM_TRAITS_CONTAINER_HPP
#define ATOM_TRAITS_CONTAINER_HPP

#include <vector>
#include <set>

namespace atom::traits::detail {
    //-------------------------------------------------------------------------
    // if X contains
    template<typename C, typename V>
    struct contains {

    };

    template<typename T>
    struct contains<std::vector<T>, T> {
        static const bool apply(const std::vector<T>& v, const T& x)
        {
            return std::find(v.begin(), v.end(), x) != v.end();
        }
    };

    template<typename T>
    struct contains<std::set<T>, T> {
        static const bool apply(const std::set<T>& v, const T& x)
        {
            return v.find(x) != v.end();
        }
    };

}

#endif // !ATOM_TRAITS_CONTAINER_HPP