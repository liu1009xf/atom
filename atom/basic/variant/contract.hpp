#ifndef ATOM_BASIC_VARIANT_CONTRACT_HPP
#define ATOM_BASIC_VARIANT_CONTRACT_HPP

#include <variant>
namespace atom::variant
{
    using contract = std::variant<std::monostate>;
} // namespace atom::variant


#endif //!ATOM_BASIC_VARIANT_CONTRACT_HPP