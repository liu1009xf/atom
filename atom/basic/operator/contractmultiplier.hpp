#ifndef ATOM_BASIC_OPERATORS_CONTRACTMULTIPLIER
#define ATOM_BASIC_OPERATORS_CONTRACTMULTIPLIER

namespace atom::detail {
    template < typename T>
    struct contract_multiplier {};

    template<>
    struct contract_multiplier<std::string>
    {
        static auto apply(std::string_view x)
        {
            return 1;
        }
    };
}

#endif /* ATOM_BASIC_OPERATORS_CONTRACTMULTIPLIER */
