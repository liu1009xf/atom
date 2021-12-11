template< typename S, typename Q , typename P >
inline const P Position<S, Q, P>::price() const
{
    return price_;
};
template< typename S, typename Q , typename P >
inline const Q Position<S, Q, P>::qty() const
{
    return qty_;
};
template< typename S, typename Q , typename P >
inline const S Position<S, Q, P>::side() const
{
    return side_;
};

template< typename S, typename Q, typename P >
Position<S, Q, P> operator+(const Position<S, Q, P>& left, const Position<S, Q, P>& right)
{
    if (left.side() == right.side()){
        auto qty = left.qty() + right.qty();
        auto price = (left.qty() * left.price() + right.qty() * right.price()) / qty;
        return Position<S, Q, P>(left.side(), qty, price);
    }
    else {
        auto qty = left.qty() - right.qty();
        if (qty >= 0) {
            return Position<S, Q, P>(left.side(), qty, left.price());
        }
        else {
            return Position<S, Q, P>(right.side(), qty, right.price());
        }
    }
}
// template< typename S, typename Q, typename P >
// friend friend Position<S, Q, P> Position<S, Q, P>::operator==(const Position<S, Q, P> other)
// {
//     return other;
// }
// template< typename S, typename Q, typename P >
// friend friend Position<S, Q, P> Position<S, Q, P>::operator!=(const Position<S, Q, P> other)
// {
//     return other;
// }
// template< typename S, typename Q, typename P >
// friend Position<S, Q, P> Position<S, Q, P>::operator>(const Position<S, Q, P> other)
// {
//     return other;
// }
// template< typename S, typename Q, typename P >
// friend Position<S, Q, P> Position<S, Q, P>::operator>=(const Position<S, Q, P> other)
// {
//     return other;
// }
// template< typename S, typename Q, typename P >
// friend Position<S, Q, P> Position<S, Q, P>::operator<(const Position<S, Q, P> other)
// {
//     return other;
// }
// template< typename S, typename Q, typename P >
// friend Position<S, Q, P> Position<S, Q, P>::operator<=(const Position<S, Q, P> other)
// {
//     return other;
// }

// template< typename S, typename Q , typename P >
// const auto Position<S, Q, P>::value() const
// {
//     return sign_of_side<S>::apply(side_) * qty_ * price_ 
//         * contract_multiplier<C>::apply(contract_);
// };
// template< typename S, typename Q , typename P >
// template<typename P1>
// const auto Position<S, Q, P>::marketValue(P1&& price) const
// {
//     return sign_of_side<S>::apply(side_) * qty_ * price
//         * contract_multiplier<C>::apply(contract_);
// };
// template< typename S, typename Q , typename P >
// template<typename P1>
// const auto Position<S, Q, P>::unrealisedProfit(P1&& price) const
// {
//     return this->marketValue(price) - value();
// };
