#ifndef ATOM_BASIC_CONTRACT_CONTRACT
#define ATOM_BASIC_CONTRACT_CONTRACT

namespace atom::detail 
{
    template<typename S, typename T, typename M>
    class Contract
    {
    public:
        Contract()=default;
        template<typename S1, typename T1, typename M1> 
        Contract(S1&& sym, T1&& assetType, M1&& multiplier) :
            sym_(sym), assetType_(assetType), multiplier_(multiplier)
        {
            
        }

        const auto sym() const;
        const auto assetType() const;
        const auto multiplier() const;
    private:
        S sym_;
        T assetType_;
        M multiplier_;
    };
    #include "impl/contract.ipp"
} // namespace atom

#endif /* ATOM_BASIC_CONTRACT_CONTRACT */
