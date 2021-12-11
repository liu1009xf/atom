#ifndef ATOM_BASIC_PORTFOLIO_PORTFOLIO
#define ATOM_BASIC_PORTFOLIO_PORTFOLIO

#include <numeric>
#include "atom/basic/operator/combine.hpp"

/** @file
 * @brief File contains implementation of Portfolio 
 * Portfolio is a container of positions. It should be able to be constracted
 * from position, positions, portfolio and other portfolios.  
 * The basic functionality of portfolio is store positions of each 
 * distinct contracts, as well as sum some summary functionalities such
 * as assets and info.
 */

namespace atom::detail
{
    /**
     * @brief 
     * 
     * @tparam M template parameter M should a map-like container type, and it
     * should have key_type and value_type.
     */
    template<typename M>
    class Portfolio
    {
    public:
        using container_type = M;
        using key_type = typename M::key_type;
        using value_type = typename M::value_type;
    public:

        /**
         * @brief 
         * 
         * @tparam K1 
         * @tparam V1 
         * @param contract 
         * @param value 
         */
        template<typename K1, typename V1>
        const void add(K1&& contract, V1&& value) const;

        /**
         * @brief 
         * 
         * @tparam K1 
         */
        template<typename K1>
        const void drop(K1&&) const;

        /**
         * @brief 
         * 
         * @return const std::vector<key_type> 
         */
        const std::vector<key_type> assets() const;

        /**
         * @brief 
         * 
         * @tparam F 
         * @param function 
         * @return const auto 
         */
        template<typename F>
        const auto info(const F& function) const;

    private:
        container_type values_;
    };
}

#endif /* ATOM_BASIC_PORTFOLIO_PORTFOLIO */
