#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <iostream>
#include "pair.hpp"
#include <memory>

namespace ft
{

template<class Key, class T>
struct nodee
{
	ft::pair<Key, T>	pair;
	Key&				key = pair.first;
	T&					value = pair.second;
	struct nodee*		left;
	struct nodee*		right;
	struct nodee*		parent;

	nodee() : left(0), right(0), parent(0), pair()
	{}
};


template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator< ft::pair<const Key, T> >
> class map
{
	public:
	typedef Key						key_type;
	typedef T						mapped_type;
	typedef ft::pair<const Key, T>	value_type;
	typedef	Compare					key_compare;
	//typedef value compare
	typedef	Allocator				allocator_type;
	
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::const_pointer		const_pointer;

	/*TO DO ITERATOR*/

	typedef ptrdiff_t				difference_type;
	typedef size_t					size_type;

	private:
	typedef	struct nodee<key_type, mapped_type>		node;
	node*		root_;
	size_type	size_;
	
};











}





#endif