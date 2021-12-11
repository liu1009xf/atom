#ifndef ATOM_BASIC_PORTFOLIO_PORTFOLIO
#define ATOM_BASIC_PORTFOLIO_PORTFOLIO

#include <numeric>
#include "atom/basic/operator/combine.hpp"

/** @file
 * @brief File contains implementation of Quote, TwoWayQuote, and TwoWayQuote builder
 *
 *
 */

namespace atom::detail
{
    template<typename M>
    class Portfolio
    {
    public:
        using container_type = M;
        using key_type = M::key_type;
        using value_type = M::value_type;
    public:
        template<typename K1, typename V1>
        const void add(K1&&c contract, V1&& value) const;

        template<typename K1>
        const void drop(K1&&) const;

        const std::vector<key_type> assets() const;


    private:
        container_type values_;
    };
}

#endif /* ATOM_BASIC_PORTFOLIO_PORTFOLIO */
