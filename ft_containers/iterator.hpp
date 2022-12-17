
#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

#include <iostream>
#include <cstddef>
#include <string>

namespace	ft{

struct random_access_iterator_tag	{};
struct forward_iterator_tag			{};
struct input_iterator_tag			{};
struct output_iterator_tag			{};

template <typename Iterator>
struct iterator_traits
{
public:
	typedef typename Iterator::difference_type	    difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer			    pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};

template <typename T>
struct iterator_traits<T*>
{
public:
	typedef std::ptrdiff_t	difference_type;
	typedef T				value_type;
	typedef T*				pointer;
	typedef T&				reference;
	typedef ft::random_access_iterator_tag iterator_category;
};

template <typename T>
struct iterator_traits<const T*>
{
public:
	typedef std::ptrdiff_t	difference_type;
	typedef T				value_type;
	typedef const T*		pointer;
	typedef const T&		reference;
	typedef ft::random_access_iterator_tag iterator_category;
};

template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	class iterator {
	public:
		typedef	T			value_type;
		typedef	Distance	difference_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;
		typedef Category	iterator_category;
};

template <class T>
	class random_access_iterator {
		
		public:
		typedef typename iterator<random_access_iterator_tag, T>::value_type		value_type;
		typedef typename iterator<random_access_iterator_tag, T>::difference_type	difference_type;
		typedef typename iterator<random_access_iterator_tag, T>::pointer			pointer;
		typedef typename iterator<random_access_iterator_tag, T>::reference			reference;
		typedef typename iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;
		typedef random_access_iterator			rai;

		// private:
		public:
		pointer	ptr;

		public:
		random_access_iterator()
		{ ptr = 0; }

		random_access_iterator(const rai& ref)
		{ ptr = ref.ptr; }

		random_access_iterator(const pointer& pointe)
		{ ptr = pointe; }

		rai&	operator=(const rai& ref)
		{
			if (*this == ref)
				return *this;
			ptr = ref.ptr; return *this; 
		}

		~random_access_iterator(){}

		bool	operator==(const rai& rhs)
		{ return (ptr == rhs.ptr); }

		bool	operator!=(const rai& rhs)
		{ return !(ptr == rhs.ptr); }

		value_type&	operator*()
		{ return *ptr; }

		value_type*	operator->()
		{ return ptr; }


		rai&	operator++()
		{ ptr++; return *this; }

		rai&	operator--()
		{ ptr--; return *this; }

		rai	operator++(int)
		{ rai tmp = *this; ptr++; return tmp; }
		
		rai	operator--(int)
		{ rai tmp = *this; ptr--; return tmp; }


		rai operator+(const difference_type n) const
		{ rai tmp(*this); tmp.ptr += n; return tmp; }

		rai operator-(const difference_type n) const
		{ rai tmp(*this); tmp.ptr -= n; return tmp; }


		// rai&	operator=(const difference_type n)
		// { ptr+=n; return *this; }
		value_type&	operator[](const difference_type i)
		{ return *(ptr + i);}

		void	print_ptr()
		{ std::cout << ptr << '\n'; }

		pointer	ret_ptr() const
		{ return ptr; }
};



template<typename T>
random_access_iterator<T> operator+(const typename iterator<random_access_iterator_tag, T>::difference_type &n,
									const ft::random_access_iterator<T> &a)
{
	random_access_iterator<T> tmp(a.ret_ptr() + n);
	return tmp;
}

template<typename T>
random_access_iterator<T> operator-(const typename iterator<random_access_iterator_tag, T>::difference_type &n,
									const ft::random_access_iterator<T> &a)
{
	random_access_iterator<T> tmp(a.ret_ptr() - n); 
	return tmp;
}

template<typename T>
typename random_access_iterator<T>::difference_type operator-(const ft::random_access_iterator<T> &lhs,
									const ft::random_access_iterator<T> &rhs)
{
	typename random_access_iterator<T>::difference_type ret;

	ret = lhs.ret_ptr() - rhs.ret_ptr();	
	return ret;
}

template<typename T>
bool operator <(const random_access_iterator<T> &a, const random_access_iterator<T> &b)
{
	return (a.ret_ptr() < b.ret_ptr());
}

template<typename T>
bool operator >(const random_access_iterator<T> &a, const random_access_iterator<T> &b)
{
	return (a.ret_ptr() > b.ret_ptr());
}

template<typename T>
bool operator <=(const random_access_iterator<T> &a, const random_access_iterator<T> &b)
{
	return (a.ret_ptr() <= b.ret_ptr());
}

template<typename T>
bool operator >=(const random_access_iterator<T> &a, const random_access_iterator<T> &b)
{
	return (a.ret_ptr() >= b.ret_ptr());
}

template<typename T>
random_access_iterator<T>& operator+=(random_access_iterator<T>& a,
		const typename random_access_iterator<T>::difference_type& b)
{
	return (a = a + b);
}

template<typename T>
random_access_iterator<T>& operator-=(random_access_iterator<T>& a,
		const typename random_access_iterator<T>::difference_type& b)
{
	return (a = a - b);
}


typedef std::string string;

}


#endif