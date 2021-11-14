#ifndef ATOM_BASIC_OPERATORS_SIDESIGN
#define ATOM_BASIC_OPERATORS_SIDESIGN

namespace atom::detail {
    template < typename T>
    struct sign_of_side {};

    template<>
    struct sign_of_side<std::string>
    {
        static auto apply(std::string_view x)
        {
            return (x == "B" || x == "Buy") ? 1 : -1;
        }
    };
}

#endif /* ATOM_BASIC_OPERATORS_SIDESIGN */
