#ifdef ATOM_CLASSNAME_PAIR
#define ATOM_CLASSNAME BOOST_PP_TUPLE_ELEM(2, 0, ATOM_CLASSNAME_PAIR)
#if BOOST_PP_TUPLE_SIZE(ATOM_CLASSNAME_PAIR) == 2
#define ATOM_BASECLASSNAME BOOST_PP_TUPLE_ELEM(2, 1, ATOM_CLASSNAME_PAIR)
#endif
#elif !defined(ATOM_CLASSNAME)
#error #define 'ATOM_CLASSNAME' or 'ATOM_CLASSNAME_PAIR'
#endif

#ifndef ATOM_CLASS_OP_NAME
#define ATOM_CLASS_OP_NAME operator()
#endif

#define ATOM_DOWNCAST_OP BOOST_PP_CAT(ATOM_CLASSNAME, _downcast)

//class defination
template <typename D>
class ATOM_CLASSNAME
#ifdef ATOM_BASECLASSNAME
    : public ATOM_BASECLASSNAME<D>
#endif
{
protected:
    using BOOST_PP_CAT(ATOM_CLASSNAME, _) = ATOM_CLASSNAME;

public:
#ifdef _Debug
    ATOM_CLASSNAME() : class_view_(classname_view())
    {
    }

    const char* class_view_ = nullptr;

    static const char* classname_view()
    {
        static const char* name = typeid(D).name();
        return name;
    }
#endif
    D& ATOM_CLASS_OP_NAME()
    {
        return ATOM_DOWNCAST_OP(*this);
    }
    const D& ATOM_CLASS_OP_NAME() const { return ATOM_DOWNCAST_OP(*this); }

private:
    template <typename Self>
    using D_ref_ = std::conditional_t<std::is_const<Self>::value, const D&, D&>;

    template <typename Self>
    static D_ref_<Self> ATOM_DOWNCAST_OP(Self& self)
    {
#ifdef _Debug
        D_ref_<Self> BOOST_PP_CAT(ATOM_CLASSNAME, _view) = static_cast<D_ref_<Self>>(self);
        (void)BOOST_PP_CAT(ATOM_CLASSNAME, _view);
#endif
        return static_cast<D_ref_<Self>>(self);
    }
};

#define ATOM_IS_CLASSNAME BOOST_PP_CAT(is_, ATOM_CLASSNAME)

//declaration
template <typename D>
struct ATOM_IS_CLASSNAME;

//alias
template <typename D>
constexpr bool BOOST_PP_CAT(ATOM_IS_CLASSNAME, _v) = ATOM_IS_CLASSNAME<D>::value;

//sub class
template <typename D>
struct ATOM_IS_CLASSNAME : std::is_base_of<ATOM_CLASSNAME<D>, D>
{
};

//base class
template <typename D>
struct ATOM_IS_CLASSNAME<ATOM_CLASSNAME<D>> : std::true_type
{
};

//const
template <typename D>
struct ATOM_IS_CLASSNAME<const D> : ATOM_IS_CLASSNAME<D>
{
};

//ref
template <typename D>
struct ATOM_IS_CLASSNAME<D&> : ATOM_IS_CLASSNAME<D>
{
};

//ref
template <typename D>
struct ATOM_IS_CLASSNAME<D&&> : ATOM_IS_CLASSNAME<D>
{
};

#undef ATOM_DOWNCAST_OP
#undef ATOM_IS_CLASSNAME
#undef ATOM_CLASSNAME
#undef ATOM_BASECLASSNAME
#undef ATOM_CLASSNAME_PAIR