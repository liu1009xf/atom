template<typename V>
TickEvent<V>::TickEvent(const std::string& datetime, const std::string& format, const V& data):
    datetime_(atom::util::str2Timepoint(datetime, format)),
    data_(data)
{

}
    
template<typename V>
TickEvent<V>::TickEvent(const std::string& datetime, const V& data) :
    datetime_(atom::util::str2Timepoint(datetime, "%Y-%m-%d %T %z")),
    data_(data)
{

}

template<typename V>
TickEvent<V>::TickEvent(const atom::util::timePoint& datetime, const V& data) :
    datetime_(datetime),
    data_(data)
{

}

template<typename V>
const auto& TickEvent<V>::datetime() const
{
    return datetime_;
}

template<typename V>
const auto& TickEvent<V>::data() const
{
    return data_;
}
