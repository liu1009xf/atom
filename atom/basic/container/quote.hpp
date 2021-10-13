#ifndef ATOM_BASIC_CONTAINER_QUOTE_HPP
#define ATOM_BASIC_CONTAINER_QUOTE_HPP

namespace atom::basic::detail
{
    template<typename V, typename Q>
    class Quote {
    public:
        Quote() = default;
        Quote(const V& value, const Q& qty);
        Quote(V&& value, Q&& qty);
        
        const auto value() const;
        const auto qty() const;
        
    private:
        V value_;
        Q qty_;
    };
    
    template<typename V>
    class TwoWayQuote {
    public:
        using value_type = V;
    public:
        TwoWayQuote() = default;
        template<typename T,
            typename S,
            std::enable_if_t<
                atom::traits::is_optional_of_v<T, V>&&
                    atom::traits::is_optional_of_v<S, V>,
                std::nullptr_t
            > = nullptr
        >
        TwoWayQuote(T&& bid, S&& ask);

        const auto bid() const;
        const auto ask() const;
        const auto bidQty() const;
        const auto askQty() const;
        const auto hasBid() const;
        const auto hasAsk() const;

    private:
        std::optional<V> bid_;
        std::optional<V> ask_;
    };

    template<typename V, typename Q>
    class TwoWayQuoteBuilder {
    public:
        using value_type = V;
        using qty_type = Q;
    public:
        TwoWayQuoteBuilder() = default;
        TwoWayQuoteBuilder(const TwoWayQuoteBuilder&) = delete;
        TwoWayQuoteBuilder(TwoWayQuoteBuilder&&) = delete;
        TwoWayQuoteBuilder& operator =(const TwoWayQuoteBuilder&) = delete;
        TwoWayQuoteBuilder& operator =(TwoWayQuoteBuilder&&) = delete;

        operator TwoWayQuote<Quote<V, Q>>() const;

        template<typename T,
            std::enable_if_t<std::is_convertible_v<T, V>, std::nullptr_t> = nullptr
        >
            TwoWayQuoteBuilder& bidPrice(T&&);
        template<typename T,
            std::enable_if_t<std::is_convertible_v<T, V>, std::nullptr_t> = nullptr
        >
            TwoWayQuoteBuilder& askPrice(T&&);
        template<typename T,
            std::enable_if_t<std::is_convertible_v<T, Q>, std::nullptr_t> = nullptr
        >
            TwoWayQuoteBuilder& bidQty(T&&);
        template<typename T,
            std::enable_if_t<std::is_convertible_v<T, Q>, std::nullptr_t> = nullptr
        >
            TwoWayQuoteBuilder& askQty(T&&);
    private:
        std::optional<V> bidPrice_;
        std::optional<V> askPrice_;
        std::optional<Q> bidQty_;
        std::optional<Q> askQty_;
    };

#include "atom/basic/container/quote.ipp"
} // namespace atom::basic


#endif //!ATOM_BASIC_CONTAINER_QUOTE_HPP
