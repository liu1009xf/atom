#ifndef ATOM_BASIC_VARIANT_LIST_BUILDER_HPP
#define ATOM_BASIC_VARIANT_LIST_BUILDER_HPP

#include "atom/basic.hpp"
#include "atom/basic/mpl/variant.hpp"

#include "atom/basic/mpl/container.hpp"
#include "atom/basic/mpl/variant.hpp"


namespace atom::variant
{
    template <typename T>
    class ListBuilder
    {
    public: 
        ListBuilder(T&& list) :list_(list) {};
        ListBuilder() :list_(T{}) {};
        ListBuilder(const ListBuilder&) = default;
        ListBuilder(ListBuilder&&) = default;
        
        template<typename S>
        const auto push_back(S&& obj) const
        {
            using VS = mpl::variant_append<typename T::value_type,
                std::remove_cv_t<std::remove_reference_t<S>>>;
            using TS = typename mpl::replace_value_type<T, VS>::type;
            TS list;
            list.reserve(list_.size() + 1);
            for (auto& x : list_)
            {
                list.push_back(atom::mpl::variant_cast(x));
            }
            list.push_back(std::forward<S>(obj));
            return ListBuilder<TS>(std::move(list));
        }
        const T list() const
        {
            return list_;
        }
    private:
        T list_;
    };
} // namespace atom::variant


#endif //!ATOM_BASIC_VARIANT_LIST_BUILDER_HPP