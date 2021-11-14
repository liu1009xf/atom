#ifndef ATOM_BASIC_CONTRACT_CONTRACT
#define ATOM_BASIC_CONTRACT_CONTRACT

namespace atom::detail 
{
    template<typename S, typename T, typename M, typename Y>
    class Contract
    {
    public:
        Contract()=default;
        template<typename S1, typename T1, typename M1, typename Y1>
        Contract(S1&& sym, T1&& assetType, M1&& multiplier, Y1 detail) :
            sym_(sym), assetType_(assetType), multiplier_(multiplier), detail_(detail)
        {
            
        }
        template<typename S1, typename T1, typename M1>
        Contract(S1&& sym, T1&& assetType, M1&& multiplier) :
            sym_(sym), assetType_(assetType), multiplier_(multiplier)
        {

        }
        const auto sym() const;
        const auto assetType() const;
        const auto multiplier() const;
        const auto detail() const;
    private:
        S sym_;
        T assetType_;
        M multiplier_;
        std::optional<Y> detail_;
    };
    #include "impl/contract.ipp"
} // namespace atom

#endif /* ATOM_BASIC_CONTRACT_CONTRACT */
