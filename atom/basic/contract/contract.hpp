#ifndef ATOM_BASIC_CONTRACT_CONTRACT
#define ATOM_BASIC_CONTRACT_CONTRACT

namespace atom::detail 
{
    template<typename S, typename T, typename M, typename C>
    class Contract
    {
    public:
        Contract()=default;
        template<typename S1, typename T1, typename M1, typename C1> 
        Contract(S1&& sym, T1&& assetType, M1&& multiplier, C1&& denominated) :
            sym_(sym), assetType_(assetType),
            multiplier_(multiplier), denominated_(denominated)
        {
            
        }

        const bool operator==(const Contract&) const;
        const auto sym() const;
        const auto assetType() const;
        const auto multiplier() const;
        const auto denominated() const;
    private:
        S sym_;
        T assetType_;
        M multiplier_;
        C denominated_;
    };
    #include "impl/contract.ipp"
} // namespace atom

#endif /* ATOM_BASIC_CONTRACT_CONTRACT */
