#ifndef ATOM_BASIC_POSITION_POSITION
#define ATOM_BASIC_POSITION_POSITION

#include "atom/basic/operator/sidesign.hpp"
#include "atom/basic/operator/contractmultiplier.hpp"

namespace atom::detail
{
    template<typename C, typename S, typename Q, typename P>
    class Position
    {
    public:

        Position() = default;
        template<typename C1, typename S1, typename Q1, typename P1>
        Position(C1&& contract, S1&& side, Q1&& qty, P1&& price) :
            contract_(std::forward<C1>(contract)),
            side_(std::forward<S1>(side)),
            qty_(std::forward<Q1>(qty)),
            price_(std::forward<P1>(price))
        {

        };;

        const P price() const;
        const Q qty() const;
        const S side() const;
        const auto value() const;
        template<typename P1>
        const auto marketValue(P1&&) const;
        template<typename P1>
        const auto unrealisedProfit(P1&&) const;
    private:
        C contract_;
        S side_;
        Q qty_;
        P price_;
    };
    #include "impl/position.ipp"
}

#endif /* ATOM_BASIC_POSITION_POSITION */
