#ifndef ATOM_AUTHORISER_TRIVAL_HPP
#define ATOM_AUTHORISER_TRIVAL_HPP


namespace atom::detail
{

    struct TrivialAuthoriser
    {
        template<typename T>
        const T authorise(const T& t) const
        {
            return t;
        }
    };

} // namespace atom


#endif //!ATOM_AUTHORISER_TRIVAL_HPP