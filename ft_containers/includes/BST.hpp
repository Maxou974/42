#include <iostream>
#include <memory>
#include "pair.hpp"
//#include "compare.hpp"

#define BLACK 1
#define RED 0

namespace ft
{

//#define key pair.first

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

template<class Key, class T, class Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T> > >
class BST
{
	public:
	typedef struct nodee<Key, T>	node;
	typedef node*					node_ptr;
	typedef std::allocator<node>	node_allocator;

	private:
	node_ptr	root_;
	size_t		size_;


	public:
	BST(){}
};




}