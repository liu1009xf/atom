#ifndef ATOM_AGENT_TRADER_TRADER_HPP
#define ATOM_AGENT_TRADER_TRADER_HPP

#include "atom/event/operator.hpp"

namespace atom::agent
{
    template<typename S>
    class Trader {
    public:

        Trader(const S& strategy) :strategy_(strategy) {};

        template<typename T>
        void process(T&& event) const
        {
            strategy_.actOn(std::forward<T>(event));
        }

        auto _strategy() const
        {
            return strategy_;
        }            
    private:
        S strategy_;
    };
} // namespace atom::agent

#endif //!ATOM_AGENT_TRADER_TRADER_HPP
