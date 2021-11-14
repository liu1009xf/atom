#ifndef ATOM_BASIC_SIGNAL_ORDER_SIGNAL_HPP
#define ATOM_BASIC_SIGNAL_ORDER_SIGNAL_HPP

namespace atom::detail
{
    class OrderSignal
    {
    public:
        inline const bool valid() const
        {
            return false;
        }
    };
} // namespace atom::detail


#endif //!ATOM_BASIC_SIGNAL_ORDER_SIGNAL_HPP
