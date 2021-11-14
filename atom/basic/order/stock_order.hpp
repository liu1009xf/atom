#ifndef ATOM_EVENT_ORDER_STOCK_ORDER_HPP
#define ATOM_EVENT_ORDER_STOCK_ORDER_HPP

#include <string>
#include <optional>

namespace atom::basic::detail
{
    class MarketOrder : public event<StockOrder>
    {
    public:
        StockOrder(
            const std::string& sym,
            double qty
        ) :sym_(sym), qty_(qty) {};

    private:
        std::string sym_;
        double qty_;
    };
} // namespace atom::event



#endif //!ATOM_EVENT_ORDER_STOCK_ORDER_HPP