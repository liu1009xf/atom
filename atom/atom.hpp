#ifndef ATOM_ATOM_HPP
#define ATOM_ATOM_HPP

#include <atom/version.h>
#include <string>

/**
 * @brief Namespace contains the entail project. 
 *
 * Namespace contains all function, classes and objects that are exposed to user of
 * the library. Any functions under sub-namespaces should be avoid, implementation
 * of functions, classes or objects may be changed without any notifications 
 */
namespace atom
{
    std::string atom_version();
} // namespace atom



#endif //ATOM_ATOM_HPP
