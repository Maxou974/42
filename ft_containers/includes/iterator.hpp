#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

#include <iostream>
#include <cstddef>
#include <string>

namespace	ft{

struct	random_access_iterator_tag	{};
struct	reverse_iterator_tag		{};
struct	bidirectional_iterator_tag	{};

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
	class random_access_iterator : public iterator<random_access_iterator_tag, T>
	{
		
		public:
		typedef typename iterator<random_access_iterator_tag, T>::value_type		value_type;
		typedef typename iterator<random_access_iterator_tag, T>::difference_type	difference_type;
		typedef typename iterator<random_access_iterator_tag, T>::pointer			pointer;
		typedef typename iterator<random_access_iterator_tag, T>::reference			reference;
		typedef typename iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;
		typedef random_access_iterator			rai;

		private:
		pointer	ptr;

		public:
		random_access_iterator() : ptr(0)
		{}

		random_access_iterator(const rai& ref) : ptr(ref.base())
		{}

		random_access_iterator(const pointer& pointe) : ptr(pointe)
		{}

		template<class Iter>
		random_access_iterator (const random_access_iterator<Iter>& ref): ptr(ref.base()){}

		rai&	operator=(const rai& ref)
		{
			if (*this == ref)
				return *this;
			ptr = ref.ptr; return *this; 
		}


		~random_access_iterator(){}

		value_type&	operator*()
		{ return *ptr; }

		value_type&	operator*() const
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


		value_type&	operator[](const difference_type i)
		{ return *(ptr + i); }

		pointer	base() const
		{ return ptr; }


};

template<typename T>
random_access_iterator<T> operator+(const typename iterator<random_access_iterator_tag, T>::difference_type &n,
									const ft::random_access_iterator<T> &a)
{
	random_access_iterator<T> tmp(a.base() + n);
	return tmp;
}

template<typename T, typename U>
typename random_access_iterator<T>::difference_type operator-(const ft::random_access_iterator<T> &lhs,
									const ft::random_access_iterator<U> &rhs)
{
	typename random_access_iterator<T>::difference_type ret;

	ret = lhs.base() - rhs.base();
	return ret;
}

template<typename T, typename U>
bool operator <(const random_access_iterator<T> &a, const random_access_iterator<U> &b)
{
	return (a.base() < b.base());
}

template<typename T, typename U>
bool operator >(const random_access_iterator<T> &a, const random_access_iterator<U> &b)
{
	return (a.base() > b.base());
}

template<typename T, typename U>
bool operator !=(const random_access_iterator<T> &a, const random_access_iterator<U> &b)
{
	return !(a.base() == b.base());
}

template<typename T, typename U>
bool operator ==(const random_access_iterator<T> &a, const random_access_iterator<U> &b)
{
	return (a.base() == b.base());
}


template<typename T, typename U>
bool operator <=(const random_access_iterator<T> &a, const random_access_iterator<U> &b)
{
	return (a.base() <= b.base());
}

template<typename T, typename U>
bool operator >=(const random_access_iterator<T> &a, const random_access_iterator<U> &b)
{
	return (a.base() >= b.base());
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



/* Reverse_iterator */
template <class Iterator>
class reverse_iterator
{
	public:
	typedef Iterator										iterator_type;
	typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef typename iterator_traits<Iterator>::value_type			value_type;
	typedef typename iterator_traits<Iterator>::difference_type		difference_type;
	typedef typename iterator_traits<Iterator>::pointer				pointer;
	typedef typename iterator_traits<Iterator>::reference			reference;

	private:
	iterator_type	it;

	public:
	reverse_iterator() : it()
	{}

	explicit reverse_iterator(const iterator_type itt)
	: it(itt)
	{}

	template <class Iter>
	reverse_iterator(const reverse_iterator<Iter>& rev_it): it(rev_it.base()) {}

	reverse_iterator(const pointer& pointe)
	{ it = pointe; }

	template<class Iter>
	reverse_iterator&	operator=(const reverse_iterator<Iter>& ref)
	{
		// if (&ref == *this)
		// 	return *this;
		it = ref.base();
		return *this;
	}

	iterator_type	base() const{ return it; }

	reverse_iterator operator+ (difference_type n) const
	{ iterator_type tmp = it ; return (reverse_iterator(tmp - n)); }

	reverse_iterator& operator+= (difference_type n)
	{ it -= n; return *this; }


	reverse_iterator operator- (difference_type n) const
	{ iterator_type tmp = it + n; return reverse_iterator(tmp); }

	reverse_iterator& operator-= (difference_type n)
	{ it = it + n; return *this; }


	reverse_iterator& operator++()
	{ it--; return *this; }

	reverse_iterator operator++(int)
	{ reverse_iterator tmp = *this; it--; return tmp; }

	reverse_iterator& operator--()
	{ it++; return *this; }

	reverse_iterator operator--(int)
	{ reverse_iterator tmp = *this; it++; return tmp; }


	reference	operator*() const { iterator_type i = it; return *(--i); }

	pointer operator->() const
	{
		iterator_type tmp = it;
		return &(*--tmp); }

	reference operator[] (difference_type n) const
	{ return (*(it - n - 1));}
};

template <typename T, typename U>
bool operator== (const reverse_iterator<T>& lhs
				,const reverse_iterator<U>& rhs)
{ return lhs.base() == rhs.base(); }

template <typename T, typename U>
bool operator!= (const reverse_iterator<T>& lhs
				,const reverse_iterator<U>& rhs)
{ return !(lhs == rhs); }

template <typename T, typename U>
bool operator<  (const reverse_iterator<T>& lhs
				,const reverse_iterator<U>& rhs)
{ return (lhs.base() > rhs.base()); }

template <typename T, typename U>
bool operator>=  (const reverse_iterator<T>& lhs
				,const reverse_iterator<U>& rhs)
{ return !(lhs.base() > rhs.base()); }

template <typename T, typename U>
bool operator>  (const reverse_iterator<T>& lhs
				,const reverse_iterator<U>& rhs)
{ return (lhs.base() < rhs.base()); }

template <typename T, typename U>
bool operator<=  (const reverse_iterator<T>& lhs
				,const reverse_iterator<U>& rhs)
{ return !(lhs.base() < rhs.base()); }

template <class Iterator>
reverse_iterator<Iterator>operator+(typename reverse_iterator<Iterator>::difference_type n
									,const reverse_iterator<Iterator>& rev_it)

{
	return reverse_iterator<Iterator>(rev_it + n);
}

template <class Iterator>
reverse_iterator<Iterator>operator-(typename reverse_iterator<Iterator>::difference_type n
									,const reverse_iterator<Iterator>& rev_it)

{
	return reverse_iterator<Iterator>(rev_it - n);
}

template <typename T, typename U>  typename reverse_iterator<T>::difference_type operator-
(const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs)
{ return  rhs.base() - lhs.base(); }


template<class T>
class bidirectional_iterator
{
	public:
	typedef typename iterator<bidirectional_iterator_tag, T>::value_type		value_type;
	typedef typename iterator<bidirectional_iterator_tag, T>::difference_type	difference_type;
	typedef typename iterator<bidirectional_iterator_tag, T>::pointer			pointer;
	typedef typename iterator<bidirectional_iterator_tag, T>::reference			reference;
	typedef typename iterator<bidirectional_iterator_tag, T>::iterator_category	iterator_category;
	
	private:
	pointer	ptr;

	public:
	bidirectional_iterator() : ptr(0)
	{}

	bidirectional_iterator(const bidirectional_iterator& ref) : ptr(ref.ptr)
	{}

	bidirectional_iterator(const pointer& pointe) : ptr(pointe)
	{}

	template<class Iter>
	bidirectional_iterator (const bidirectional_iterator<Iter>& ref): ptr(ref.ptr){}

	bidirectional_iterator&	operator=(const bidirectional_iterator& ref)
	{
		if (*this == ref)
			return *this;
		ptr = ref.ptr; return *this; 
	}

			~bidirectional_iterator(){}

		bool	operator==(const bidirectional_iterator& rhs)
		{ return (ptr == rhs.ptr); }

		bool	operator!=(const bidirectional_iterator& rhs)
		{ return !(ptr == rhs.ptr); }

		value_type&	operator*()
		{ return *ptr; }

		value_type&	operator*() const
		{ return *ptr; }

		value_type*	operator->()
		{ return ptr; }

		value_type*	operator->() const
		{ return ptr; }

		bidirectional_iterator&	operator++()
		{ ptr++; return *this; }

		bidirectional_iterator&	operator--()
		{ ptr--; return *this; }

		bidirectional_iterator	operator++(int)
		{ bidirectional_iterator tmp = *this; ptr++; return tmp; }
		
		bidirectional_iterator	operator--(int)
		{ bidirectional_iterator tmp = *this; ptr--; return tmp; }

		pointer	base() const
		{ return ptr; }
};

template <class Iterator>
bool operator== (const bidirectional_iterator<Iterator>& lhs
				,const bidirectional_iterator<Iterator>& rhs)
{ return lhs.base() == rhs.base(); }

template <class Iterator>
bool operator!= (const bidirectional_iterator<Iterator>& lhs
				,const bidirectional_iterator<Iterator>& rhs)
{ return !(lhs == rhs); }

}


#endif