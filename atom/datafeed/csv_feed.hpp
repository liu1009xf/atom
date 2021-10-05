#ifndef ATOM_COMPONENT_DATAFEED_CSV_FEED_HPP
#define ATOM_COMPONENT_DATAFEED_CSV_FEED_HPP

#include <string>
#include <vector>

#include <csv.hpp>

#include "atom/basic/variant/contract.hpp"

namespace atom::datafeed
{
    template<typename V=double>
    class CSVGeneralFeed {
    public:
        using value_type = V;
    public:
        CSVGeneralFeed(const Observers) {
            
        }

        void feed(const contract& contract, std::string_view filePath, std::string_view ) const {
            csv::CSVReader reader(filePath);
            auto ks = reader.get_col_names();
            for (auto& row : reader) { // Input iterator
                std::map<std::string, V> mp;
                for (std::string_view k : ks)
                {
                    for (auto& o : observers_)
                        atom::component::TickData()
                        if (contract == atom::variant::get_contract(o))
                        {
                            atom::variant::notify(o, )
                        }
                }
                    std::cout << row["date"].get<std::string>() << ","
                    
            }
        }
    private:
        std::vector<Observer> observers_;
    }
} // namespace atom::datafeed


#endif //!ATOM_COMPONENT_DATAFEED_CSV_FEED_HPP