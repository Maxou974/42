#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <iostream>
#include "pair.hpp"
#include "iterator.hpp"
#include <memory>

#define key pair.first
#define value pair.second

namespace ft
{



template<class Key, class T>
struct nodee
{
	ft::pair<const Key, T>	pair;
	struct nodee*		left;
	struct nodee*		right;
	struct nodee*		parent;

	nodee() : pair(), left(0), right(0), parent(0)
	{}

	nodee(const nodee& ref) :  pair(ref.pair), left(ref.left), right(ref.right), parent(ref.parent)
	{
		// left = ref.left;
		// right = ref.right;
		// parent = ref.parent;
	}

	nodee&	operator=(const nodee& ref)
	{
		if (this == &ref)
			return *this;
		left = ref.left;
		right = ref.right;
		parent = ref.parent;
		pair = ref.pair;
		return *this;
	}

	nodee(const ft::pair<const Key, T>& ref) : pair(ref), left(0), right(0), parent(0)
	{
		// pair.first = ref.first;
		// pair.second = ref.second;
	}


	~nodee(){};
};

template<class Key, class T, class Compare = std::less<Key> >
class bst
{
	public:
	typedef Key		key_type;
	typedef T		mapped_type;

	private:
	typedef	struct nodee<Key, T>		node;
	typedef ft::pair<const Key, T>	value_type;

	Compare					comp;
	node*					root_;
	size_t					size_;
	std::allocator<node>	alloc_;

	public:
	bst() : root_(0), size_(0), alloc_(std::allocator<node>()) {}



	void	clear()
	{
		recursive_clear(root_);
		size_ = 0;
		root_ = 0;
	}

	~bst()
	{
		clear();
	}

	node* insert(const value_type pairr)
	{
		// if (search(pairr.first))
		// 	return;
		node*	y = 0;
		node*	x = root_;
		node*	z = alloc_.allocate(1);
		alloc_.construct(z, node(pairr));
		while (x != 0)
		{
			y = x;
			if (comp(z->key, x->key))
				x = x->left;
			else
				x = x->right;
		}
		z->parent = y;
		if (y == 0)
			root_ = z;
		else if (comp(z->key, y->key))
			y->left = z;
		else
			y->right = z;
		size_++;
		return z;
	}

	node*	search(const key_type& keyy) const
	{
		node*	ptr = root_;
		while (ptr != 0 && keyy != ptr->key)
		{
			if (comp(keyy, ptr->key))
				ptr = ptr->left;
			else
				ptr = ptr->right;
		}
		return ptr;
	}

	node*	max(node* x) const
	{
		while (x->right != 0)
			x = x->right;
		return x;
	} node*	max() const { return max(root_); }

	node*	min(node* x) const
	{
		while (x->left != 0)
			x = x->left;
		return x;
	} node*	min() const { return min(root_); }

	node*	successor(node*	x) const
	{
		if (x->right)
			return min(x->right);
		node*	y = x->parent;
		while (y != 0 && x == y->right)
		{
			x = y;
			y = y->parent;
		}
		return y;
	}

	node*	predecessor(node*	x) const
	{
		if (x->left)
			return max(x->left);
		node*	y = x->parent;
		while (y != 0 && x == y->left)
		{
			x = y;
			y = y->parent;
		}
		return y;
	}
	// void	shiftnode(node* u, node *v)
	// {
	// 	if (u->parent == 0)
	// 		root_ = v;
	// 	else if (u == u->parent->left)
	// 		u->parent->left = v;
	// 	else
	// 		u->parent->right = v;
	// 	if (v != 0)
	// 		v.parent = u.parent;
	// }

	bool	is_leaf(node* x)const
	{
		return !(x->right || x->left);
	}

	bool	as_only_one_child(node* x)const
	{
		// XOR
		int a = 0;
		if (x->right)
		a++;
		if (x->left)
		a++;
		return a % 2;
	}

	void	erase(const key_type& keyy )
	{
		node* x;
		if (!(x = search(keyy)))
			return;
		if (is_leaf(x))
		{
			if (x == root_)
				root_ = 0;
			else if (x->parent->left == x)
				x->parent->left = NULL;
			else
				x->parent->right = NULL;
		}
		else if (as_only_one_child(x))
		{
			if (x->parent == NULL)
			{
				if (x->right)
					root_ = x->right;
				else
					root_ = x->left;
				root_->parent = NULL;
			}
			else if(x->parent->left == x)
			{
				x->parent->left = reinterpret_cast<node*>(
				reinterpret_cast<long>(x->right) + reinterpret_cast<long>(x->left));
				x->parent->left->parent = x->parent;
			}
			else
			{
				x->parent->right = reinterpret_cast<node*>(
				reinterpret_cast<long>(x->right) + reinterpret_cast<long>(x->left));
				x->parent->right->parent = x->parent;
			}
		}
		else
		{
			node*	y = successor(x);
			//imediate right child
			if (y == x->right)
			{
				y->left = x->left;
				y->parent = x->parent;
				if (x->parent->right == x)
					x->parent->right = y;
				else
					x->parent->left = y;
				x->left->parent = y;
			}
			else
			{
				y->parent->left = y->right;
				if (y->right)
					y->right->parent = y->parent;
				x->right->parent = y;
				y->parent = x->parent;
				y->left = x->left;
				y->right = x->right;
				if (y->left)
				y->left->parent  = y->left;
			}
			if (x == root_)
				root_ = y;
		}
		// alloc_.destroy(x);
		alloc_.deallocate(x, 1);
		size_--;
	}

	size_t	get_size() const { return size_; }

	node*	get_root() const { return root_;}

	void	s(node* x, int i) const
	{
		if (x != 0)
		{
			s(x->left, i+1);
			// std::cout << x->key << " level: " << i; 
			std::cout << x->key; 
			if (x->right)
				std::cout << "  right:" << x->right->key; 
			else
				std::cout << "  right:NULL"; 

			if (x->left)
				std::cout << "  left:" << x->left->key; 
			else
				std::cout << "  left:NULL";
			if (x->parent)
				std::cout << "  parent:" << x->parent->key;
			else
				std::cout << "  parent:NULL";
			std::cout << '\n';
			s(x->right, i+1);
		}
	}

	void	show() const
	{
		if (root_ == 0 || size_ == 0)
			std::cout << "EMPTY TREE";
		else
			s(root_, 0);
		std::cout << '\n';
	}

	private:
	void	recursive_clear(node* ptr)
	{
		if (ptr == 0)
			return ;
		node* save = ptr->right;
		recursive_clear(ptr->left);
		alloc_.deallocate(ptr, 1);
		recursive_clear(save);
	}

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
	

	typedef ptrdiff_t				difference_type;
	typedef size_t					size_type;

		private:
		typedef	struct nodee<key_type, mapped_type>		node;
		typedef	node*	node_ptr;
		class map_iterator
		{
			private:
			node* ptr;
			bst<key_type, mapped_type> tree;
	
			public:
			map_iterator() : ptr(0)
			{}
	
			map_iterator(const map_iterator& ref) : ptr(ref.ptr)
			{}
	
			map_iterator(const node_ptr& ptr) : ptr(ptr)
			{}
	
			map_iterator&	operator=(const map_iterator& ref)
			{
				if (this == &ref)
					return *this;
				ptr = ref.ptr;
				return *this;
			}
	
			~map_iterator(){}
	
			value_type&	operator*()
			{
				return ptr->pair;
			}
	
			map_iterator& operator++()
			{
				ptr = tree.successor(ptr); return *this;
			}
			map_iterator operator++(int)
			{
				map_iterator tmp = *this;
				ptr = tree.successor(ptr); 
				return tmp;
			}
		};
	public:
	typedef map_iterator		iterator;


	private:
	bst<key_type, mapped_type, key_compare>	tree_;
	allocator_type									alloc_;
	
	public:
	map() : tree_(), alloc_(allocator_type())
	{}
	
	
	ft::pair<map_iterator, bool> insert(const value_type& val)
	{
		node *x;
		if ( (x = tree_.search(val.first)) )
			return ft::make_pair<iterator, bool>(iterator(x), false);
		return ft::make_pair<iterator, bool>(iterator(tree_.insert(val)), true);
	}

	void show(){tree_.show();};
	void clear(){tree_.clear();};





















};


}





#endif