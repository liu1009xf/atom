#ifndef ATOM_BASIC_VISITOR_GET_SYMBOL_HPP
#define ATOM_BASIC_VISITOR_GET_SYMBOL_HPP

// namespace atom::visitor
// {
//     template<typename S>
//     class GetSymbolVisitor
//     {
//     public:
//         GetSymbolVisitor() = delete;
//         GetSymbolVisitor(const GetSymbolVisitor&) = delete;
//         GetSymbolVisitor(GetSymbolVisitor&&) = delete;

//         GetSymbolVisitor(S&& symbol) :symbol_(symbol) {};
//         GetSymbolVisitor(const S& symbol) :symbol_(symbol) {};

//         template<typename T>
//         bool operator()(const T& t) {
//             return atom::traits::contains<typename T::sym_type, S>::apply(t, symbol_);
//         }
//     private:
//         S symbol_;
//     };
// } // namespace atom::visitor

#endif //!ATOM_BASIC_VISITOR_GET_SYMBOL_HPP