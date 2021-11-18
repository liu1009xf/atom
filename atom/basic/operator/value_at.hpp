#ifndef ATOM_BASIC_OPERATOR_VALUE_AT
#define ATOM_BASIC_OPERATOR_VALUE_AT

#include <map>
namespace atom::detail
{
    template<typename M, typename K>
    struct value_at
    {
        static constexpr int apply(const M&, const K&)
        {
            return 1;
        }
    };

    template<typename K, typename V, typename K1>
    struct value_at<std::map<K, V>, K1>
    {
        static_assert(std::is_convertible_v<K1, K>);
        static constexpr V apply(const std::map<K, V>& m, const K1& k)
        {
            return m.at(k);
        }
    };
} // namespace atom::detail


#endif /* ATOM_BASIC_OPERATOR_VALUE_AT */
