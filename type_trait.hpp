
template <class _Tp> struct remove_const { typedef _Tp type; };
template <class _Tp> struct remove_const<const _Tp> { typedef _Tp type; };

template <class _Tp> struct remove_volatile { typedef _Tp type; };
template <class _Tp> struct remove_volatile<volatile _Tp> { typedef _Tp type; };

template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };

template <class _Tp, _Tp __v>
struct integral_constant
{
    static const _Tp      value = __v;
    typedef _Tp               value_type;
    typedef integral_constant type;
    operator value_type() const {return value;}
};

typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;


template< class _Tp > struct is_integral_filter : public false_type {};
template<> struct is_integral_filter<bool> : public true_type {};
template<> struct is_integral_filter<char> : public true_type {};
template<> struct is_integral_filter<signed char> : public true_type {};
template<> struct is_integral_filter<unsigned char> : public true_type {};
template<> struct is_integral_filter<wchar_t> : public true_type {};
template<> struct is_integral_filter<char16_t> : public true_type {};
template<> struct is_integral_filter<char32_t> : public true_type {};
template<> struct is_integral_filter<short> : public true_type {};
template<> struct is_integral_filter<unsigned short> : public true_type {};
template<> struct is_integral_filter<int> : public true_type {};
template<> struct is_integral_filter<unsigned int> : public true_type {};
template<> struct is_integral_filter<long> : public true_type {};
template<> struct is_integral_filter<unsigned long> : public true_type {};
template<> struct is_integral_filter<long long> : public true_type {};
template<> struct is_integral_filter<unsigned long long> : public true_type {};

template <class _Tp>
struct is_integral : is_integral_filter<typename remove_volatile<typename remove_const<_Tp>::type>::type> {};
