#ifndef ATOM_COMPONENT_DATAFEED_CSV_FEED_HPP
#define ATOM_COMPONENT_DATAFEED_CSV_FEED_HPP

#include <string>
#include <vector>

#include <csv.hpp>

#include "atom/basic/variant/contract.hpp"

namespace atom::datafeed
{
    class CSVGeneralFeed {
    public:
        using value_type = V;
    public:
        CSVGeneralFeed(const Observers)
        {
            
        }

        template<typename V>
        void feed(const contract& contract,
            std::string_view filePath,
            std::string_view format) const
        {
            feed_impl
        }
    private:
        std::vector<Observer> observers_;

        void feed_impl(const contract& contract,
            std::string_view filePath,
            std::string_view dtFormat) const
        {
            csv::CSVReader reader(filePath);
            auto ks = reader.get_col_names();
            for (auto& row : reader) { // Input iterator
                std::map<std::string, value_type> mp;
                for (auto i = 1;i<ks.size();++i)
                {
                    mp[k] = row[k].get<value_type>();
                }
                atom::component::TickData td(rowp[k[0]].get<>(), dtFormat, mp);
                for (auto& o : observers_)
                if (contract == atom::variant::get_symbol(o))
                {
                    atom::variant::get_notified(td)(o);
                }
                std::cout << row["date"].get<std::string>() << ","

            }
        }
    }
} // namespace atom::datafeed


#endif //!ATOM_COMPONENT_DATAFEED_CSV_FEED_HPP