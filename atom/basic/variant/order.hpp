#ifndef ATOM_BASIC_VARIANT_ORDER_HPP
#define ATOM_BASIC_VARIANT_ORDER_HPP

#include <variant>
namespace atom::variant
{
    using order = std::variant<std::monostate>;
} // namespace atom::variant


#endif //!ATOM_BASIC_VARIANT_ORDER_HPP