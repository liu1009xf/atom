#ifndef ATOM_EVENT_OPERATOR_HPP
#define ATOM_EVENT_OPERATOR_HPP

namespace atom::op {
    template<typename T>
    const auto eval(const T& t)
    {
        return t.show();
    }
} // namespace atom::operator


#endif //!ATOM_EVENT_OPERATOR_HPP