// template<typename S, typename Q , typename P >
// template<typename C1, typename S1, typename Q1, typename P1>
// Position<S, Q, P>::Position(C1&& contract, S1&& side, Q1&& qty, P1&& price) :
//     contract_(std::forward<C1>(contract)),
//     side_(std::forward<S1>(side)),
//     qty_(std::forward<Q1>(qty)),
//     price_(std::forward<P1>(price))
// {

// };


template<typename S, typename Q , typename P >
const P Position<S, Q, P>::price() const
{
    return price_;
};
template<typename S, typename Q , typename P >
const Q Position<S, Q, P>::qty() const
{
    return qty_;
};
template<typename S, typename Q , typename P >
const S Position<S, Q, P>::side() const
{
    return side_;
};

template<atom::enums::Side S, typename Q, typename P >
const P SidedPosition<S, Q, P>::price() const
{
    return price_;
};

template<atom::enums::Side S, typename Q, typename P >
const Q SidedPosition<S, Q, P>::qty() const
{
    return qty_;
};

template<atom::enums::Side S,  typename Q, typename P >
const auto SidedPosition<S, Q, P>::side() const
{
    return side_;
};

template<typename Q, typename P>
auto operator+(SidedPosition<enums::Side::BUY, Q, P> l, SidedPosition<enums::Side::SELL, Q, P> r)
{
    auto qty = l.qyt() - r.qty();
    if (static_cast<bool>((Q(0) < qty) - (qty < Q(0))))
    {
        return SidedPosition<enums::Side::BUY, Q, P>(qty, l.price());
    }
    else {
        return SidedPosition<enums::Side::SELL, Q, P>(-1*qty, r.price());
    }
}

template<typename Q, typename P>
auto operator+(SidedPosition<enums::Side::SELL, Q, P> l, SidedPosition<enums::Side::BUY, Q, P> r)
{
    return r + l;
}
template<typename Q, typename P>
auto operator+(SidedPosition<enums::Side::SELL, Q, P> l, SidedPosition<enums::Side::SELL, Q, P> r)
{
    auto qty = l.qty() + r.qty();
    return SidedPosition<enums::Side::SELL, Q, P>(qty, (l.price()*l.qty() + r.qty()*r.price()) / qty);
};

template<typename Q, typename P>
auto operator+(SidedPosition<enums::Side::BUY, Q, P> l, SidedPosition<enums::Side::BUY, Q, P> r)
{
    auto qty = l.qty() + r.qty();
    return SidedPosition<enums::Side::BUY, Q, P>(qty, (l.price()*l.qty() + r.qty()*r.price()) / qty);
};

// template<typename S, typename Q , typename P >
// const auto Position<S, Q, P>::value() const
// {
//     return sign_of_side<S>::apply(side_) * qty_ * price_ 
//         * contract_multiplier<C>::apply(contract_);
// };
// template<typename S, typename Q , typename P >
// template<typename P1>
// const auto Position<S, Q, P>::marketValue(P1&& price) const
// {
//     return sign_of_side<S>::apply(side_) * qty_ * price
//         * contract_multiplier<C>::apply(contract_);
// };
// template<typename S, typename Q , typename P >
// template<typename P1>
// const auto Position<S, Q, P>::unrealisedProfit(P1&& price) const
// {
//     return this->marketValue(price) - value();
// };