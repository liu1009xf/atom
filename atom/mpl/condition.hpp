#ifndef ATOM_MPL_CONDITION
#define ATOM_MPL_CONDITION

namespace atom::mpl
{
    template<bool...v>
    struct all {
        static constexpr bool value = (v && ...);
    };

    template<bool...v>
    struct any {
        static constexpr bool value = (v || ...);
    };
}

#endif /* ATOM_MPL_CONDITION */
