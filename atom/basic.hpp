#ifndef ATOM_BASIC_HPP
#define ATOM_BASIC_HPP

#include <optional>
#include <type_traits>

#include "atom/basic/type_traits.hpp"

#include "atom/basic/container/quote.hpp"
#include "atom/basic/visitor/event_notify.hpp"
#include "atom/basic/visitor/get_symbol.hpp"
#include "atom/basic/signal/order_signal.hpp"
#include "atom/basic/position/position.hpp"
#include "atom/basic/portfolio/portfolio.hpp"
#include "atom/basic/contract/contract.hpp"

#include "atom/basic/decorator/with_meta.hpp"

namespace atom {
    template <typename V = double, typename Q = unsigned long int>
    using Quote = basic::detail::Quote<V, Q>;
    template <typename V = Quote<double, unsigned long int>>
    using TwoWayQuote = basic::detail::TwoWayQuote<V>;

    template<typename V = double, typename Q = unsigned long int>
    using TwoWayQuoteBuilder = basic::detail::TwoWayQuoteBuilder<V, Q>;
    
    using OrderSignal = detail::OrderSignal;

    template<typename S = std::string,typename Q = double, typename P = double>
    using Position = detail::Position<S, Q, P>;

    template<typename P = Position<>>
    using Portfolio = detail::Portfolio<P>;

    template<typename S=std::string, typename T=std::string, typename M=int, typename C=std::string>
    using Contract = detail::Contract<S, T, M, C>;

    //--------------------------------------------------------------------------
    // Visitor
    //
    template<typename E>
    using EventNotifyVisitor = visitor::EventNotifyVisitor<E>;
    // template<typename E>
    // using GetSymbolVisitor = atom::visitor::GetSymbolVisitor<E>;

    //--------------------------------------------------------------------------
    // Decorator
    //
    template<typename T, typename M = std::map<std::string, std::string>>
    using WithMeta = detail::WithMeta<T, M>;
}

#endif //!ATOM_BASIC_HPP