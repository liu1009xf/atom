template<typename S1, typename T1, typename M1, typename C1>
const auto Contract<S1,T1,M1,C1>::sym() const
{
    return sym_;
};

template<typename S1, typename T1, typename M1, typename C1>
const auto Contract<S1, T1, M1, C1>::assetType() const
{
    return assetType_;
};

template<typename S1, typename T1, typename M1, typename C1>
const auto Contract<S1, T1, M1, C1>::multiplier() const
{
    return multiplier_;
};

template<typename S1, typename T1, typename M1, typename C1>
const auto Contract<S1, T1, M1, C1>::denominated() const
{
    return denominated_;
};

template<typename S1, typename T1, typename M1, typename C1>
const bool Contract<S1, T1, M1, C1>::operator==(const Contract& other) const
{
    return sym_ == other.sym() &&
        assetType_ == other.assetType() &&
        multiplier_ == other.multiplier() &&
        denominated_ == other.denominated();
}
