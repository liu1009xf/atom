// template<typename C, typename S, typename Q , typename P >
// template<typename C1, typename S1, typename Q1, typename P1>
// Position<C, S, Q, P>::Position(C1&& contract, S1&& side, Q1&& qty, P1&& price) :
//     contract_(std::forward<C1>(contract)),
//     side_(std::forward<S1>(side)),
//     qty_(std::forward<Q1>(qty)),
//     price_(std::forward<P1>(price))
// {

// };

template<typename C, typename S, typename Q , typename P >
const P Position<C, S, Q, P>::price() const
{
    return price_;
};
template<typename C, typename S, typename Q , typename P >
const Q Position<C, S, Q, P>::qty() const
{
    return qty_;
};
template<typename C, typename S, typename Q , typename P >
const S Position<C, S, Q, P>::side() const
{
    return side_;
};
template<typename C, typename S, typename Q , typename P >
const auto Position<C, S, Q, P>::value() const
{
    return sign_of_side<S>::apply(side_) * qty_ * price_ 
        * contract_multiplier<C>::apply(contract_);
};
template<typename C, typename S, typename Q , typename P >
template<typename P1>
const auto Position<C, S, Q, P>::marketValue(P1&& price) const
{
    return sign_of_side<S>::apply(side_) * qty_ * price
        * contract_multiplier<C>::apply(contract_);
};
template<typename C, typename S, typename Q , typename P >
template<typename P1>
const auto Position<C, S, Q, P>::unrealisedProfit(P1&& price) const
{
    return this->marketValue(price) - value();
};