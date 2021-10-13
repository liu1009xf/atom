template<typename T>
template<typename W,
    typename S,
    std::enable_if_t<
        atom::traits::is_optional_of_v<W, T>&&
            atom::traits::is_optional_of_v<S, T>,
        std::nullptr_t
    >
>
TwoWayQuote<T>::TwoWayQuote(W&& bid, S&& ask) :bid_(bid), ask_(ask) {};

template<typename T>
const auto TwoWayQuote<T>::bid() const
{
    return bid_.value().value();
}

template<typename T>
const auto TwoWayQuote<T>::ask() const
{
    return ask_.value().value();
}

template<typename T>
const auto TwoWayQuote<T>::bidQty() const
{
    return  bid_.value().qty();;
}

template<typename T>
const auto TwoWayQuote<T>::askQty() const
{
    return ask_.value().qty();
}

template<typename T>
const auto TwoWayQuote<T>::hasBid() const
{
    return bid_.has_value();
}

template<typename T>
const auto TwoWayQuote<T>::hasAsk() const
{
    return ask_.has_value();
}
template<typename T, typename S>
Quote<T, S>::Quote(
    const T& value, const S& qty) : value_(value), qty_(qty){};

template<typename T, typename S>
Quote<T, S>::Quote(
    T&& value, S&& qty) : value_(value), qty_(qty) {};

template<typename T, typename S>
const auto Quote<T, S>::value() const
{
    return value_;
}

template<typename T, typename S>
const auto Quote<T, S>::qty() const
{
    return qty_;
}

template<typename V, typename Q>
template<typename T,
    std::enable_if_t<std::is_convertible_v<T, V>, std::nullptr_t>
>
TwoWayQuoteBuilder<V, Q>& TwoWayQuoteBuilder<V, Q>::bidPrice(T&& bidPrice)
{
    this->bidPrice_ = bidPrice;
    return *this;
}

template<typename V, typename Q>
template<typename T,
    std::enable_if_t<std::is_convertible_v<T, V>, std::nullptr_t>
>
TwoWayQuoteBuilder<V, Q>& TwoWayQuoteBuilder<V, Q>::askPrice(T&& askPrice)
{
    this->askPrice_ = askPrice;
    return *this;
}

template<typename V, typename Q>
template<typename T,
    std::enable_if_t<std::is_convertible_v<T, Q>, std::nullptr_t>
>
TwoWayQuoteBuilder<V, Q>& TwoWayQuoteBuilder<V, Q>::bidQty(T&& bidQty)
{
    this->bidQty_ = bidQty;
    return *this;
}

template<typename V, typename Q>
template<typename T,
    std::enable_if_t<std::is_convertible_v<T, Q>, std::nullptr_t>
>
TwoWayQuoteBuilder<V, Q>& TwoWayQuoteBuilder<V, Q>::askQty(T&& askQty)
{
    this->askQty_ = askQty;
    return *this;
}

template<typename V, typename Q>
TwoWayQuoteBuilder<V, Q>::operator TwoWayQuote<Quote<V, Q>>() const
{
    using osd = Quote<V, Q>;
    if (bidPrice_.has_value() && askPrice_.has_value())
    {
        auto bq = bidQty_.has_value() ? bidQty_.value() : static_cast<Q>(0);
        auto aq = askQty_.has_value() ? askQty_.value() : static_cast<Q>(0);
        return TwoWayQuote<osd>(osd(bidPrice_.value(), bq),
            osd(askPrice_.value(), aq));
    }
    else if (bidPrice_.has_value())
    {
        auto bq = bidQty_.has_value() ? bidQty_.value() : static_cast<Q>(0);
        return TwoWayQuote<osd>(Quote(bidPrice_.value(), bq), std::nullopt);
    }
    else if (askPrice_.has_value())
    {
        auto aq = askQty_.has_value() ? askQty_.value() : static_cast<Q>(0);
        return TwoWayQuote<osd>(std::nullopt, Quote(askPrice_.value(), aq));
    }
    else {
        return TwoWayQuote<osd>(std::nullopt, std::nullopt);
    }
}
