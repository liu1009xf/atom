#ifndef ATOM_BASIC_DECORATOR_META_DEC
#define ATOM_BASIC_DECORATOR_META_DEC

namespace atom::detail {

    template<typename T, typename M>
    class WithMeta : public T
    {
    public:
        WithMeta() = default;

        template<typename M1, typename ...TA>
        WithMeta(M1&& meta, TA&&... args) : T(args...), meta_(meta) {};

        inline const auto meta() const
        {
            return meta_;
        }
    private:
        M meta_;
    };
}

#endif /* ATOM_BASIC_DECORATOR_META_DEC */
