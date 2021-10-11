#ifndef ATOM_BASIC_CONTAINER_QUOTE_HPP
#define ATOM_BASIC_CONTAINER_QUOTE_HPP

namespace atom::basic::detail
{
    template<typename V, typename Q>
    class OneSideQuote {
    public:
        OneSideQuote() = default;
        OneSideQuote(const V& value, const Q& qty);
        OneSideQuote(V&& value, Q&& qty);
        
        const auto value() const;
        const auto qty() const;
        const auto hasQty() const;
        
    private:
        V value_;
        std::optional<Q> qty_;
    };
    
    template<typename V>
    class Quote {
    public:
        using value_type = V;
    public:
        Quote() = default;
        Quote(const V& bid, const V& ask);
        template<typename T,
            typename S,
            std::enable_if_t<
            std::conjunction_v<
            std::is_same_v<T, V> || std::is_same_v<T, std::nullopt_t>,
            std::is_same_v<S, V> || std::is_same_v<S, std::nullopt_t>
            >, std::nullptr_t> = nullptr
        >
            Quote(T&& bid, S&& ask);

        const auto bid() const;
        const auto ask() const;
        const auto bidQty() const;
        const auto askQty() const;

    private:
        std::optional<V> bid_;
        std::optional<V> ask_;
    };

#include "atom/basic/container/quote.ipp"
} // namespace atom::basic


#endif //!ATOM_BASIC_CONTAINER_QUOTE_HPP
