#ifndef ATOM_BASIC_VARIANT_STRATEGY_HPP
#define ATOM_BASIC_VARIANT_STRATEGY_HPP

#include "atom/strategy/strategy_base.hpp"

namespace atom::variant
{
    using strategy = std::variant<
        std::monostate,
        std::unique_ptr<atom::strategy::StrategyBase>
    >;
} // namespace atom::bas


#endif //!ATOM_BASIC_VARIANT_STRATEGY_HPP