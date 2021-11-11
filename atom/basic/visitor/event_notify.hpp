#ifndef ATOM_BASIC_VISITOR_EVENT_NOTIFY_HPP
#define ATOM_BASIC_VISITOR_EVENT_NOTIFY_HPP

namespace atom::visitor
{
    template<typename E>
    class EventNotifyVisitor
    {
    public:
        EventNotifyVisitor() = delete;
        EventNotifyVisitor(const EventNotifyVisitor&) = delete;
        EventNotifyVisitor(EventNotifyVisitor&&) = delete;

        EventNotifyVisitor(E&& event) :event_(event) {};
        EventNotifyVisitor(const E& event) :event_(event) {};

        template<typename T>
        void operator()(const T& t) {
            t.process(event_);
        }

    private:
        E event_;
    };
} // namespace atom::visitor

#endif //!ATOM_BASIC_VISITOR_EVENT_NOTIFY_HPP