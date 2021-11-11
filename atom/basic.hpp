#ifndef ATOM_BASIC_HPP
#define ATOM_BASIC_HPP

#include <optional>
#include <type_traits>

#include "atom/type_traits.hpp"

#include "atom/basic/container/quote.hpp"
#include "atom/basic/visitor/event_notify.hpp"
#include "atom/basic/visitor/get_symbol.hpp"

namespace atom {
    template <typename V = double, typename Q = unsigned long int>
    using Quote = basic::detail::Quote<V, Q>;
    template <typename V=Quote<double, unsigned long int>>
    using TwoWayQuote = basic::detail::TwoWayQuote<V>;

    template<typename V = double, typename Q = unsigned long int>
    using TwoWayQuoteBuilder = basic::detail::TwoWayQuoteBuilder<V, Q>;

    //--------------------------------------------------------------------------
    // Visitor
    //
    template<typename E>
    using EventNotifyVisitor = atom::visitor::EventNotifyVisitor<E>;
    template<typename E>
    using GetSymbolVisitor = atom::visitor::GetSymbolVisitor<E>;
}

#endif //!ATOM_BASIC_HPP