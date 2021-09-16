#ifndef ATOM_UTIL_DATETIME_TIMEPOINT_HPP
#define ATOM_UTIL_DATETIME_TIMEPOINT_HPP

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <date/date.h>

namespace atom::util::tp::detail
{
    using timePoint = date::sys_time<std::chrono::microseconds>;

    inline timePoint str2Timepoint(
        const std::string& sdt,
        const std::string& formate = "%Y-%m-%d %T %z")
    {
        timePoint dt;
        std::istringstream in{ sdt };
        in >> date::parse(formate, dt);
        return dt;
    }

    template<typename TP_T>
    inline auto timepoint2Str(TP_T&& tp)
    {
        return date::format("%F %T %z", std::forward<TP_T>(tp));
    }
} // namespace atom::util::tp::detail

#endif //!ATOM_UTIL_DATETIME_TIMEPOINT_HPP