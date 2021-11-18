template<typename S1, typename T1, typename M1>
const auto Contract<S1,T1,M1>::sym() const
{
    return sym_;
};

template<typename S1, typename T1, typename M1>
const auto Contract<S1, T1, M1>::assetType() const
{
    return assetType_;
};

template<typename S1, typename T1, typename M1>
const auto Contract<S1, T1, M1>::multiplier() const
{
    return multiplier_;
};
