#include <atom/atom.hpp>

/** @file
 * @brief This is a "brief" explaination of this file
 *
 * This is a "Detailed" explaination of this file
 */

 /**
  * @brief Brief explaination of namespace MyNamespace
  *
  * Detailed explaination of namespace MyNamespace
  */
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