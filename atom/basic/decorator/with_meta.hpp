#ifndef ATOM_BASIC_DECORATOR_WITH_META
#define ATOM_BASIC_DECORATOR_WITH_META

#include "atom/basic/operator/value_at.hpp"
#include "atom/basic/mpl/helper.hpp"

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

        template<typename K>
        inline const auto meta(const K& key) const
        {
            return value_at<M, K>::apply(meta_, key);
        }
    private:
        M meta_;
    };
}

#endif /* ATOM_BASIC_DECORATOR_WITH_META */
