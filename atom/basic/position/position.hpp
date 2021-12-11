#ifndef ATOM_BASIC_POSITION_POSITION
#define ATOM_BASIC_POSITION_POSITION

#include "atom/basic/operator/sidesign.hpp"
#include "atom/basic/operator/contractmultiplier.hpp"
#include "atom/basic/operator/equal.hpp"

namespace atom::detail
{
    template<typename S, typename Q, typename P>
    class Position
    {
    public:
        using side_type = S;
        using qty_type = Q;
        using price_type = P;
    public:
        Position() = default;
        template<typename S1, typename Q1, typename P1>
        Position(S1&& side, Q1&& qty, P1&& price) :
            side_(std::forward<S1>(side)),
            qty_(std::forward<Q1>(qty)),
            price_(std::forward<P1>(price))
        {

        };
        

        const P price() const;
        const Q qty() const;
        const S side() const;

        bool operator==(const Position& other) const=default;
    private:
        S side_;
        Q qty_;
        P price_;
    };
    #include "impl/position.ipp"
}

#endif /* ATOM_BASIC_POSITION_POSITION */
