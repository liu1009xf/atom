#ifndef ATOM_AGENT_TRADER_TRADER_HPP
#define ATOM_AGENT_TRADER_TRADER_HPP

#include "atom/event/operator.hpp"

namespace atom::base{
    struct Decision {};
}

namespace atom::agent
{   
    class Trader {
    public:
        
        template<typename T>
        void process(T&& event) const
        {
            std::cout << "trader processing " << atom::op::eval(event) << std::endl;
        }
        
    private:
        void trade(atom::base::Decision o) const {
            
        }
    };
} // namespace atom::agent

#endif //!ATOM_AGENT_TRADER_TRADER_HPP
