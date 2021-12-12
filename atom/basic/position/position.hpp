#ifndef ATOM_BASIC_POSITION_POSITION
#define ATOM_BASIC_POSITION_POSITION

#include "atom/basic/operator/sidesign.hpp"
#include "atom/basic/operator/contractmultiplier.hpp"
#include "atom/mpl/condition.hpp"
#include "atom/mpl/helper.hpp"

#include "position_expr.hpp"

namespace atom::detail
{
    template<typename S, typename Q, typename P>
    class Position : public position<Position<S, Q, P>>
    {
    public:
        Position() = default;
        template< typename S1, typename Q1, typename P1,
            std::enable_if_t<atom::mpl::all<
                    std::is_convertible_v<mpl::remote_const_ref_t<S1>, S>,
                    std::is_convertible_v<mpl::remote_const_ref_t<Q1>, Q>,
                    std::is_convertible_v<mpl::remote_const_ref_t<P1>, P>
            >::value, std::nullptr_t> = nullptr
        >
        Position(S1&& side, Q1&& qty, P1&& price) :
            side_(std::forward<S1>(side)),
            qty_(std::forward<Q1>(qty)),
            price_(std::forward<P1>(price))
        {

        };
        
        const P price() const;
        const Q qty() const;
        const S side() const;
    private:
        S side_;
        Q qty_;
        P price_;
    };

    template<atom::enums::Side S, typename Q, typename P>
    class SidedPosition : public position<SidedPosition<S, Q, P>>
    {
    public:
        static constexpr atom::enums::Side side_ = S;
    public:
        SidedPosition() = default;
        template< typename Q1, typename P1,
            std::enable_if_t<atom::mpl::all<
            std::is_convertible_v<mpl::remote_const_ref_t<Q1>, Q>,
            std::is_convertible_v<mpl::remote_const_ref_t<P1>, P>
        >::value, std::nullptr_t> = nullptr>
        SidedPosition(Q1&& qty, P1&& price) :
            qty_(std::forward<Q1>(qty)),
            price_(std::forward<P1>(price))
        {

        };

        const auto side() const;
        const P price() const;
        const Q qty() const;
    private:
        Q qty_;
        P price_;
    };

    template<typename Q, typename P>
    auto operator+(SidedPosition<enums::Side::BUY,  Q, P>, SidedPosition<enums::Side::SELL, Q, P>);

    template<typename C, typename Q, typename P>
    auto operator+(SidedPosition<enums::Side::SELL, Q, P>, SidedPosition<enums::Side::BUY, Q, P>);

    template<typename C, typename Q, typename P>
    auto operator+(SidedPosition<enums::Side::SELL, Q, P>, SidedPosition<enums::Side::SELL, Q, P>);

    template<typename C, typename Q, typename P>
    auto operator+(SidedPosition<enums::Side::BUY, Q, P>, SidedPosition<enums::Side::BUY, Q, P>);
#include "impl/position.ipp"
}

#endif /* ATOM_BASIC_POSITION_POSITION */
