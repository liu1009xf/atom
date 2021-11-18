#ifndef ATOM_AGGREGATOR_ORDER_BOOK
#define ATOM_AGGREGATOR_ORDER_BOOK

namespace atom::detail
{
    template<typename S, typename Q>
    class OrderBook
    {
    public:
        
    private:
        S sym_;
        std::vector<Q> bidQuotes_;
        std::vector<Q> askQuotes_;
    }
} // namespace atom::detail

#endif /* ATOM_AGGREGATOR_ORDER_BOOK */
