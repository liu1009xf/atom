#ifndef ATOM_BASIC_VARIANT_DECISION_HPP
#define ATOM_BASIC_VARIANT_DECISION_HPP

#include <variant>
namespace atom::variant
{
    using decision = std::variant<std::monostate>;
} // namespace atom::variant

#endif //!ATOM_BASIC_VARIANT_DECISION_HPP