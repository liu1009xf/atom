#ifndef ATOM_BASIC_OPERATOR_EQUAL
#define ATOM_BASIC_OPERATOR_EQUAL

namespace atom::detail {

    template<typename T, typename S>
    struct equals
    {
        static constexpr bool apply(const T& t, const S& s) {
            return t == s;
        }
    };

}

#endif /* ATOM_BASIC_OPERATOR_EQUAL */
