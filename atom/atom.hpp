#ifndef ATOM_ATOM_HPP
#define ATOM_ATOM_HPP

#include <atom/version.h>
#include <string>

/**
 * @brief Namespace contains all functions classes and objects that are exposed to users. 
 *
 * Namespace contains all function, classes and objects that are exposed to user of
 * the library. Any functions under sub-namespaces should be avoid, since implementations
 * of functions, classes or objects under any sub-namespaces may be changed without
 * any notifications.
 */
namespace atom
{
    std::string atom_version();
} // namespace atom



#endif //ATOM_ATOM_HPP
