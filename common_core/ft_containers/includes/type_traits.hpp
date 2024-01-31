#ifndef FT_TYPE_TRAITS_HPP
#define FT_TYPE_TRAITS_HPP

namespace ft {

template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };



template <class T, bool v>
struct is_integral_const
{
	typedef T value_type;
	static const bool value = v;
	typedef is_integral_const<T, v> type;
	operator T(){ return value; }
	T operator()(void) const { return value; }
};


template <class T>
struct is_integral : is_integral_const<T, false>
{};

template<>
struct is_integral<bool> : public ft::is_integral_const<bool, true>
{};

template<>
struct is_integral<char> : public ft::is_integral_const<char, true>
{};

template<>
struct is_integral<wchar_t> : public ft::is_integral_const<wchar_t, true>
{};

template<>
struct is_integral<signed char> : public ft::is_integral_const<signed char, true>
{};

template<>
struct is_integral<short int> : public ft::is_integral_const<short int, true>
{};

template<>
struct is_integral<int> : public ft::is_integral_const<int, true>
{};

template<>
struct is_integral<long int> : public ft::is_integral_const<long int, true>
{};

template<>
struct is_integral<long long int> : public ft::is_integral_const<long long int, true>
{};

template<>
struct is_integral<unsigned char> : public ft::is_integral_const<unsigned char, true>
{};

template<>
struct is_integral<unsigned short int> : public ft::is_integral_const<unsigned short int, true>
{};

template<>
struct is_integral<unsigned int> : public ft::is_integral_const<unsigned int, true>
{};

template<>
struct is_integral<unsigned long int> : public ft::is_integral_const<unsigned long int, true>
{};

template<>
struct is_integral<unsigned long long int> : public ft::is_integral_const<unsigned long long int, true>
{};



}

#endif