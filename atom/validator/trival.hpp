#ifndef ATOM_VALIDATOR_TRIVAL_HPP
#define ATOM_VALIDATOR_TRIVAL_HPP

namespace atom::detail
{
    struct TrivialValidator
    {
        template<typename T>
        const T authorise(const T& t) const
        {
            return t;
        }
    };
}

#endif // !ATOM_VALIDATOR_TRIVAL_HPP