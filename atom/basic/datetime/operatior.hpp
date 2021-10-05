#ifndef ATOM_UTIL_DATETIME_OPERATIOR_HPP
#define ATOM_UTIL_DATETIME_OPERATIOR_HPP

#include <chrono>

namespace atom::util
{
    template<typename T>
    struct get_time_now;

    template<>
    struct get_time_now<std::chrono::system_clock>
    {
        static auto apply([[maybe_unused]] const std::chrono::system_clock&)
        {
            return std::chrono::time_point_cast<std::chrono::microseconds>(
                std::chrono::system_clock::now());
        }
    };

    // temporary class
    struct my_clock_t {
        auto now() const {
            return std::chrono::system_clock::now();
        }
    };
    
    template<>
    struct get_time_now<my_clock_t>
    {
        static auto apply(const my_clock_t& clock)
        {
            return std::chrono::time_point_cast<std::chrono::microseconds>(
                clock.now());
        }
    };
} // namespace atom::util::tp::detail

#endif //!ATOM_UTIL_DATETIME_OPERATIOR_HPP