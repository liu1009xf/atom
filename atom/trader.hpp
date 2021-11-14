#ifndef ATOM_TRADER_HPP
#define ATOM_TRADER_HPP

#include "atom/basic/validator/trival.hpp"
#include "atom/basic/authoriser/trival.hpp"
#include "atom/basic/operator/eventnotifier.hpp"

#include "atom/trader/trader.hpp"
namespace atom
{
    template<typename S, typename C, typename OO,
        typename LP = detail::TrivialValidator,
        typename AF = detail::TrivialAuthoriser
    >
    using Trader = detail::Trader<S, C, OO, LP, AF>;
}

#endif //!ATOM_TRADER_HPP
