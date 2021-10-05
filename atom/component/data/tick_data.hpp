#ifndef ATOM_COMPONENT_DATA_TICK_DATA_HPP
#define ATOM_COMPONENT_DATA_TICK_DATA_HPP

#include <string>
#include <map>
#include <vector>

#include "atom/basic/datetime/timepoint.hpp"

/** @file
 * @brief File contains implementation of TickData
 *
 */

namespace atom::component
{
    /**
     * @brief Generalised Tick Data contains time and data of type map<string, T>
     *
     * Class that contains a timepoint that the data became available, e.g. if data
     * is quote data, then the timepoint is the time tht the quote first became
     * aviable, in the case of trade, timepoint is the time where the trade is done.
     * Data is the content stored in map, e.g. for quote, this could be {{bid,100}, {ask,101}}.
     *
     */
    template<typename T>
    class TickData {
    public:
        /**
         * @brief Default Constructer is set to default
         *
         * Default Constructer is set to default.
         */
        TickData() = default;

        /**
         * @brief Constructer takes data and string date with given format
         *
         * @param datetime  string datetime
         * @param format string datetime format
         * @param data map contains key and data value, e.g {{bid:100}, {ask:101}}
         */
        TickData(const std::string& datetime,
            const std::string& format,
            std::map<std::string, T> data) :
            datetime_(atom::util::str2Timepoint(datetime, format)),
            data_(data),
            keys_(this->getDataFields_(data))
        {

        }

        /**
         * @brief Constructer takes data and string date using default format
         *
         * @param datetime  string datetime
         * @param data map contains key and data value, e.g {{bid:100}, {ask:101}}
         */
        TickData(const std::string& datetime,
            std::map<std::string, T> data) :
            datetime_(atom::util::str2Timepoint(datetime, "%Y-%m-%d %T %z")),
            data_(data),
            keys_(this->getDataFields_(data))
        {

        }

        /**
         * @brief Constructer takes data and string date using default format
         *
         * @param datetime  atom::timePoint type datetime
         * @param data map contains key and data value, e.g {{bid:100}, {ask:101}}
         */
        TickData(const atom::util::timePoint& datetime,
            std::map<std::string, T> data) :
            datetime_(datetime),
            data_(data),
            keys_(this->getDataFields_(data))
        {

        }

        /**
         * @brief retrive datetime
         *
         * @return const timePoint refernce of datetime stored.
         */
        const auto& getDatetime() const
        {
            return datetime_;
        }

        /**
         * @brief retrive all data
         *
         * @return const map refernce of data stored.
         */
        const auto& getData() const
        {
            return data_;
        }

        /**
         * @brief retrive data with given key
         *
         * @param key  string key to a specific piece of data stored
         * @return const T refernce of data stored.
         */
        const auto& getData(std::string key) const
        {
            return data_.at(key);
        }

        /**
         * @brief retrive all keys
         *
         * @return const vecoter<string> refernce of keys stored.
         */
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