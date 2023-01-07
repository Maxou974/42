#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include "vector.hpp"

namespace ft{

template <class T, class Container = ft::vector<T> >
class stack
{
public:
	typedef T			value_type;
	typedef Container	container_type;
	typedef size_t		size_type;

protected:
	container_type c;

public:
	explicit stack(const container_type& chtr = container_type()) : c(chtr)
	{}

	bool	empty() const
	{ return c.empty(); }

	size_type size() const{
		return c.size();
	}

	value_type& top(){
		return c.back();
	}

	const value_type& top() const {
		return c.back();
	}

	void push (const value_type& val){
		c.push_back(val);
	}

	void	pop(){
		c.pop_back();
	}

	template <class TT, class Containerr>
	friend bool operator== (const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs);

	template <class TT, class Containerr>
	friend bool operator< (const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs);

};

template <class TT, class Containerr>
bool operator== (const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs)
{
	return lhs.c == rhs.c;
}

template <class TT, class Containerr>
bool operator!= (const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs)
{
	return !(lhs == rhs);
}

template <class TT, class Containerr>
bool operator< (const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs)
{
	return lhs.c < rhs.c;
}

template <class TT, class Containerr>
bool operator> (const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs)
{
	return rhs < lhs;
}

template <class TT, class Containerr>
bool operator<= (const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs)
{
	return !(lhs > rhs);
}

template <class TT, class Containerr>
bool operator>= (const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs)
{
	return !(lhs < rhs);
}

}
#endif