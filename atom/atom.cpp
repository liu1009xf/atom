#include <atom/atom.hpp>

namespace atom
{
    std::string atom_version()
    {
        #if (ATOM_DEBUG)
        return std::string(ATOM_VERSION) + " Debug";
        #else
        return std::string(ATOM_VERSION) + " Release";
        #endif
    }
}