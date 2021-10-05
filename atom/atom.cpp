#include <iostream>
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
    void atom_print_version(void)
    {
        #if (ATOM_DEBUG)
                const char* m = "Debug";
        #else
                const char* m = "Not debug";
        #endif

        std::cout << "This is foo version " << ATOM_VERSION << " " << m << std::endl;
    }
}