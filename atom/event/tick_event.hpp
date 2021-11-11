#ifndef ATOM_COMPONENT_DATA_TICK_EVENT_HPP
#define ATOM_COMPONENT_DATA_TICK_EVENT_HPP

#include <string>
#include <map>
#include <vector>

#include "atom/basic/datetime/timepoint.hpp"

/** @file
 * @brief File contains implementation of TickEvent
 *
 */

namespace atom::event::detail
{
    template<typename T> class event;
    /**
     * @brief Tick Data contains time and data of type map<string, T>
     *
     * Class that contains a timepoint that the data became available, e.g. if data
     * is quote data, then the timepoint is the time tht the quote first became
     * aviable, in the case of trade, timepoint is the time where the trade is done.
     * Data is the content stored in map, e.g. for quote, this could be {{bid,100}, {ask,101}}.
     *
     * \todo TODO: Add meta information to tick_event
     *           for example, which broker is the quote in this tick event from.
     *           strategy can favour one broker over another
     *           because of the commission scheme.
     *
     */
    template<typename T>
    class TickEvent : public event<TickEvent<T>> {
    public:
        using value_type = T;
    public:
        /**
         * @brief Default Constructer is set to default
         *
         * Default Constructer is set to default.
         */
        TickEvent() = default;

        /**
         * @brief Constructer takes data and string date with given format
         *
         * @param datetime  string datetime
         * @param format string datetime format
         * @param data map contains key and data value, e.g {{bid:100}, {ask:101}}
         */
        TickEvent(const std::string& datetime, const std::string& format, const T& data);

        /**
         * @brief Constructer takes data and string date using default format
         *
         * @param datetime  string datetime
         * @param data map contains key and data value, e.g {{bid:100}, {ask:101}}
         */
        TickEvent(const std::string& datetime, const T& data);

        /**
         * @brief Constructer takes data and string date using default format
         *
         * @param datetime  atom::timePoint type datetime
         * @param data map contains key and data value, e.g {{bid:100}, {ask:101}}
         */
        TickEvent(const atom::util::timePoint& datetime, const T& data);

        /**
         * @brief retrive datetime
         *
         * @return const timePoint refernce of datetime stored.
         */
        const auto& datetime() const;

        /**
         * @brief retrive all data
         *
         * @return const map refernce of data stored.
         */
        const auto& data() const;
        
    private:
        atom::util::timePoint datetime_;
        T data_;  
    };
    #include "atom/event/impl/tick_event.ipp"
} // namespace atom::component

#endif //!ATOM_COMPONENT_DATA_TICK_EVENT_HPP