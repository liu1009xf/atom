#ifndef ATOM_FEEDER_FEEDER
#define ATOM_FEEDER_FEEDER

namespace atom::detail
{
    template<typename O, typename N>
    class Feeder
    {
    public:
        using E = typename N::event_type;
    public:
        template<typename O1>
        Feeder(O1&& observers) :observers_(observers) {};

        template<typename E1,
            std::enable_if_t<std::is_convertible_v<E1, E>,
            nullptr_t> = nullptr
        >
        void feed(E1&& event) const
        {
            N::apply(event, observers_);
        }
    private:
        O observers_;
    };
} // namespace atom::detail


#endif /* ATOM_FEEDER_FEEDER */
