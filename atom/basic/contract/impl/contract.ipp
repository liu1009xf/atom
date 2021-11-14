template<typename S1, typename T1, typename M1, typename Y1>
const auto Contract<S1,T1,M1,Y1>::sym() const
{
    return sym_;
};

template<typename S1, typename T1, typename M1, typename Y1>
const auto Contract<S1, T1, M1, Y1>::assetType() const
{
    return assetType_;
};

template<typename S1, typename T1, typename M1, typename Y1>
const auto Contract<S1, T1, M1, Y1>::multiplier() const
{
    return multiplier_;
};

template<typename S1, typename T1, typename M1, typename Y1>
const auto Contract<S1, T1, M1, Y1>::detail() const
{
    return detail_;
};