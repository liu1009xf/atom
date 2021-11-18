#ifndef ATOM_BASIC_OPERATOR_EVENTNOTIFIER
#define ATOM_BASIC_OPERATOR_EVENTNOTIFIER


namespace atom::detail
{
    template<typename E, typename O>
    struct event_notifier
    {
        static void apply(const E&, const O&) {
            
        }
    };
}

#endif /* ATOM_BASIC_OPERATOR_EVENTNOTIFIER */
