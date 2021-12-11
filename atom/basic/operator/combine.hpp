#ifndef ATOM_BASIC_OPERATOR_COMBINE
#define ATOM_BASIC_OPERATOR_COMBINE

#include <cmath>

#include "equal.hpp"

namespace atom::detail {

    // template <typename T, typename S>
    // struct combinable
    // {
    //     static constexpr bool apply(const T& t, const S& s)
    //     {
    //         return t == s;
    //     }
    // };

    // template <typename T1, typename T2, typename T3>
    // struct combinable<Position<T1,T2,T3>, Position<T1,T2,T3>>
    // {
    //     static constexpr bool apply(const Position<T1, T2, T3>& t,
    //         const Position<T1, T2, T3>& s)
    //     {
    //         return equals<
    //             typename Position<T1, T2, T3>::contract_type, 
    //             typename Position<T1, T2, T3>::contract_type
    //         >::apply(t.contract(), s.contract());
    //     }
    // };

    // template <typename T, typename S>
    // struct combine
    // {
    //     static constexpr auto  apply(const T& t, const S& s)
    //     {
    //         return t+s;
    //     }
    // };

    // template <typename T1, typename T2, typename T3>
    // struct combine<Position<T1, T2, T3>, Position<T1, T2, T3>>
    // {
    //     using Pos = Position<T1, T2, T3>;
    //     static constexpr std::vector<Pos> apply(const Pos& t,
    //         const Pos& s)
    //     {
    //         std::vector<Pos> pos;
    //         if (t.side() != s.side() && t.qty() == s.qty())
    //         {
    //             return pos;
    //         }
    //         auto side = t.qty() > s.qty() ? t.side() : s.side();
    //         auto qty = t.side() != s.side() ?
    //             std::abs(t.qty() - s.qty()) : t + s;
    //         // auto price = t.
    //         // Pos(
    //         //     t.contract(),

    //         //     )
    //     }
    // };
    
}

#endif /* ATOM_BASIC_OPERATOR_COMBINE */
