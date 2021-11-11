#ifndef ATOM_COMPONENT_DATAFEED_CSV_FEED_HPP
#define ATOM_COMPONENT_DATAFEED_CSV_FEED_HPP

#include <string>
#include <vector>

#include <csv.hpp>

#include "atom/basic/variant/contract.hpp"
#include "atom/event.hpp"
#include "atom/basic.hpp"

namespace atom::datafeed
{

    template<typename O>
    class CSVGeneralFeed {
    public:
        CSVGeneralFeed(const O& Observers) :
        {

        }

        template<typename V>
        void feed(const V& contract,
            std::string_view filePath,
            std::string_view format) const
        {
            feed_impl(constract, filePath, format);
        }
    private:
        O observers_;

        template<typename V>
        void feed_impl(const V& symbol,
            std::string_view filePath,
            std::string_view dtFormat) const
        {
            csv::CSVReader reader(filePath);
            for (auto& row : reader) { // Input iterator
                atom::TwoWayQuoteBuilder<double, int> twqb;
                using v = decltype(twqb)::value_type;
                using q = decltype(twqb)::qty_type;
                auto twq= twqb.bidPrice(row[1].get<v>())
                            .bidQty(row[2].get<q>())
                            .askPrice(row[3].get<v>())
                            .askQty(row[4].get<q>());
                atom::TickEvent<atom::TwoWayQuoteBuilder<double, int>> t(row[0].get(), twq);
                atom::EventNotifyVisitor eventNotify(t);
                for (auto& o : observers_)
                {
                    atom::GetSymbolVisitor getSymbol(symbol);
                    if (std::visit(getSymbol, o))
                    {
                        std::visit(eventNotify, o);
                    }
                }
            }
        }
    };
} // namespace atom::datafeed


#endif //!ATOM_COMPONENT_DATAFEED_CSV_FEED_HPP