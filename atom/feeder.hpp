#ifndef ATOM_FEEDER
#define ATOM_FEEDER

#include "atom/feeder/feeder.hpp"

namespace atom
{
    template<typename O, typename N>
    using Feeder = detail::Feeder<O, N>;
}

#endif /* ATOM_FEEDER */
