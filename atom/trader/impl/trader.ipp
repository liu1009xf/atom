template<typename S, typename C, typename OO, typename LP, typename AF>
Trader<S, C, OO, LP, AF>::Trader(const S& strategy) :strategy_(strategy) {};

template<typename S, typename C, typename OO, typename LP, typename AF>
Trader<S, C, OO, LP, AF>::Trader(const S& strategy, const C& baseCurrency) :
    strategy_(strategy), baseCurrency_(baseCurrency) {};

template<typename S, typename C, typename OO, typename LP, typename AF>
template<typename T>
inline void Trader<S, C, OO, LP, AF>::process(T&& event) const
{
    auto raw_signal = strategy_.actOn(std::forward<T>(event));

    auto validatedSignal = tradingLimitation_.value_or(TrivialValidator())
        .validate(raw_signal);
    auto authorisedSignal = validatedSignal.valid() ?
        authorisationFlow_.value_or(TrivialAuthoriser())
        .authorise(std::move(validatedSignal)) : raw_signal;

    if (authorisedSignal.valid()) {
        for (const auto& oo : orderObservers_) {
            event_notifier<std::remove_const_t<
                std::remove_reference_t<decltype(authorisedSignal)>>, OO
            >::apply(authorisedSignal, oo);
        }
    }
}

template<typename S, typename C, typename OO, typename LP, typename AF>
void Trader<S, C, OO, LP, AF>::addOrderObserver(const OO& observer) const
{
    orderObservers_.push_back(observer);
}
// template<typename O//,
//     // std::enable_if_t<
//     // std::is_convertible_v<O, OO>,
//     // std::nullptr_t
//     // > = nullptr
// >
// void addOrderObserver(const O& observer) const;
