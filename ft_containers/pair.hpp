#ifndef	FT_VECTOR_HPP
#define	FT_VECTOR_HPP

namespace ft
{

template< typename T1, typename T2 >
struct pair
{
	typedef T1	first_type;
	typedef T2	second_type;

	first_type	first;
	second_type	second;

	pair()
	{ first(); second(); }

	template < typename T1, typename T2 >
	pair(const pair<U, V>& pr) : first(pr.first), second(pr.second)
	{}

	pair(const first_type& a, const second_type& b) : first(a), second(b)
	{}


	pair&	operator=(const pair& pr)
	{
		if (*this == ref)
			return *this;
		first(pr.first);
		second(pr.second);
		return *this;
	}
};

template <typename T1, typename T2>
  bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return lhs.first==rhs.first && lhs.second==rhs.second; }

template <typename T1, typename T2>
  bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return !(lhs==rhs); }

template <typename T1, typename T2>
  bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return lhs.first<rhs.first || (rhs.first == lhs.first && lhs.second<rhs.second); }

template <typename T1, typename T2>
  bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return !(rhs<lhs); }

template <typename T1, typename T2>
  bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return rhs<lhs; }

template <typename T1, typename T2>
  bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return !(lhs<rhs); }

template< typename T1, typename T2 >
ft::pair<T1, T2>	make_pair(T1 a, T2 b)
{ return ft::pair<T1, T2>(a, b); }

}

#endif