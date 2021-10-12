template<typename T>
Quote<T>::Quote(const T& bid, const T& ask) :bid_(bid), ask_(ask) {};

template<typename T>
template<typename W,
    typename S,
    std::enable_if_t<
    std::conjunction_v<
        std::disjunction_v<std::is_same<W, T>, std::is_same<W, std::nullopt_t>>,
        std::disjunction_v<std::is_same<S, T>, std::is_same<S, std::nullopt_t>>
        >,
        std::nullptr_t
    >
>
Quote<T>::Quote(W&& bid, S&& ask) :bid_(bid), ask_(ask) {};

template<typename T>
const auto Quote<T>::bid() const
{
    return bid_.value().value();
}

template<typename T>
const auto Quote<T>::ask() const
{
    return ask_.value().value();
}

template<typename T>
const auto Quote<T>::bidQty() const
{
    return  bid_.value().qty();;
}

template<typename T>
const auto Quote<T>::askQty() const
{
    return ask_.value().qty();
}

template<typename T, typename S>
OneSideQuote<T, S>::OneSideQuote(
    const T& value, const S& qty) : value_(value), qty_(qty){};

template<typename T, typename S>
OneSideQuote<T, S>::OneSideQuote(
    T&& value, S&& qty) : value_(value), qty_(qty) {};

template<typename T, typename S>
const auto OneSideQuote<T, S>::value() const
{
    return value_;
}

template<typename T, typename S>
const auto OneSideQuote<T, S>::qty() const
{
    return qty_.value();
}

template<typename T, typename S>
const auto OneSideQuote<T, S>::hasQty() const
{
    return qty_.hasValue();
}
    