#ifndef ATOM_BASIC_MPL_HELPER
#define ATOM_BASIC_MPL_HELPER

namespace atom::mpl {
    template <typename T>
    struct remote_const_ref
    {
        using type = typename std::remove_const<
            typename std::remove_reference< T >::type
        >::type ;
    };

    template <typename T>
    using remote_const_ref_t = typename remote_const_ref<T>::type;
}

#endif /* ATOM_BASIC_MPL_HELPER */
