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
	container_type tab;

public:
	explicit stack(const container_type& chtr = container_type()) : tab(chtr)
	{}

	bool	empty() const
	{ return tab.empty(); }

	size_type size() const{
		return tab.size();
	}

	value_type& top(){
		return tab.back();
	}

	const value_type& top() const {
		return tab.back();
	}

	void push (const value_type& val){
		tab.push_back(val);
	}

	void	pop(){
		tab.pop_back();
	}

	template <class TT, class Containerr>
	friend bool operator== (const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs);

	template <class TT, class Containerr>
	friend bool operator< (const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs);

};

template <class TT, class Containerr>
bool operator== (const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs)
{
	return lhs.tab == rhs.tab;
}

template <class TT, class Containerr>
bool operator!= (const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs)
{
	return !(lhs == rhs);
}

template <class TT, class Containerr>
bool operator< (const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs)
{
	return lhs.tab < rhs.tab;
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