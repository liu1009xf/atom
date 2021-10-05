#ifndef ATOM_COMPONENT_DATA_TICK_DATA_HPP
#define ATOM_COMPONENT_DATA_TICK_DATA_HPP

#include <string>
#include <map>
#include <vector>

#include "atom/basic/datetime/timepoint.hpp"

namespace atom::component
{
    template<typename T>
    class TickData {
    public:
        TickData(const std::string& datetime,
            const std::string& dateformat,
            std::map<std::string, T> data) :
            datetime_(atom::util::str2Timepoint(datetime, dateformat)),
            data_(data),
            keys_(this->getDataFields_(data))
        {

        }

        const auto& getTime() const
        {
            return datetime_;
        }

        const auto& getData() const
        {
            return data_;
        }

        const auto& getData(std::string key) const
        {
            return data_.at(key);
        }
        
        const auto& getKeys() const
        {
            return keys_;
        }
    private:
        atom::util::timePoint datetime_;
        std::map<std::string, T> data_;
        std::vector<std::string> keys_;
        
        const auto getDataFields_(std::map<std::string, T> m) const
        {
            std::vector<std::string> keys;
            std::transform(m.begin(), m.end(),
                std::back_inserter(keys),
                [](auto pair) { return pair.first; });
            return keys;
        }
    };
} // namespace atom::component

#endif //!ATOM_COMPONENT_DATA_TICK_DATA_HPP