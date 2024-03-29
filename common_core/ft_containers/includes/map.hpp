#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <iostream>
#include "pair.hpp"
#include "compare.hpp"
#include "iterator.hpp"
#include <memory>

namespace ft
{

template<class Key, class T, class Value_Type>
class map_iterator;


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
	{}

	~nodee(){};
};


// #####  #####  #####  
// #   #  #        #    
// #####  #####    #    
// #   #      #    #    
// #####  #####    #    


template<class Key, class T, class Compare, class Allocator>
class bst
{
	public:
	typedef Key		key_type;
	typedef T		mapped_type;

	private:
	typedef	struct nodee<Key, T>		node;
	typedef ft::pair<const Key, T>		value_type;
	typedef	Compare						key_compare;
	typedef	Allocator					allocator_type;


	key_compare					comp;
	node*					root_;
	node*					end;
	size_t					size_;
	typename allocator_type::template rebind<node>::other	alloc_;

	public:
	explicit bst(const key_compare& com = key_compare(), const allocator_type &alloc = allocator_type())
	: comp(com), root_(0), end(0), size_(0), alloc_(alloc)
	{
		alloc_ = typename allocator_type::template rebind<node>::other();
		end = alloc_.allocate(1);
		alloc_.construct(end, node());

	}

	bst(const bst& ref) : root_(0), size_(0), alloc_(ref.alloc_)
	{
		end = alloc_.allocate(1);
		alloc_.construct(end, node());
		recursive_insert(ref.root_);
	}

	bst&	operator=(const bst& ref)
	{
		if (this == &ref)
			return *this;
		clear();
		alloc_ = ref.alloc_;
		recursive_insert(ref.root_);
		end->right = root_;
		return *this;
	}

	void	clear()
	{
		recursive_clear(root_);
		size_ = 0;
		root_ = 0;
	}

	~bst()
	{
		clear();
		alloc_.destroy(end);
		alloc_.deallocate(end, 1);
	}

	node* insert(const value_type pairr)
	{
		node* tmp;
		if ( (tmp = search(pairr.first)) )
			return tmp;
		node*	y = 0;
		node*	x = root_;
		node*	z = alloc_.allocate(1);
		alloc_.construct(z, node(pairr));
		while (x != 0)
		{
			y = x;
			if (comp(z->pair.first, x->pair.first))
				x = x->left;
			else
				x = x->right;
		}
		z->parent = y;
		if (y == 0)
			root_ = z;
		else if (comp(z->pair.first, y->pair.first))
			y->left = z;
		else
			y->right = z;
		size_++;
		end->right = root_;
		return z;
	}

	node*	search(const key_type& keyy) const
	{
		node*	ptr = root_;
		while (ptr != 0 && keyy != ptr->pair.first)
		{
			if (comp(keyy, ptr->pair.first))
				ptr = ptr->left;
			else
				ptr = ptr->right;
		}
		return ptr;
	}

	static node*	max(node* x)
	{
		while (x && x->right != 0)
			x = x->right;
		return x;
	} node*	max() const { return max(root_); }

	static node*	min(node* x)
	{
		while (x && x->left != 0)
			x = x->left;
		return x;
	} node*	min() const { return min(root_); }

	static node*	successor(node*	x)
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

	static node*	predecessor(node*	x)
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
				x->parent->left = 0;
			else
				x->parent->right = 0;
		}
		else if (as_only_one_child(x))
		{
			if (x->parent == 0)
			{
				if (x->right)
					root_ = x->right;
				else
					root_ = x->left;
				root_->parent = 0;
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
				if (x->parent != 0 && x->parent->right == x)
					x->parent->right = y;
				else if (x->parent != 0)
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
		// x->parent = 0;
		// x->left = 0;
		// x->right = 0;
		alloc_.destroy(x);
		alloc_.deallocate(x, 1);
		end->right = root_;
		size_--;
	}

	size_t	get_size() const { return size_; }

	static node* get_root_from_ptr(node* x)
	{
		while (x->parent)
			x = x->parent;
		return x;
	}

	void	set_end(node* p)
	{ end = p; }
	void	set_root(node* p)
	{ root_ = p; }
	void	set_size(size_t t)
	{  size_ = t; }
	node*	get_end() const
	{ return end; }
	node*	get_root() const
	{ return root_; }

	size_t max_size() const
	{ return alloc_.max_size(); }

	private:
	void	recursive_clear(node* ptr)
	{
		if (ptr == 0)
			return ;
		node* save = ptr->right;
		recursive_clear(ptr->left);
		alloc_.destroy(ptr);
		alloc_.deallocate(ptr, 1);
		recursive_clear(save);
	}

	void	recursive_insert(node* ptr)
	{
		if (ptr == 0)
			return ;
		insert(ptr->pair);
		recursive_insert(ptr->left);
		recursive_insert(ptr->right);
	}

};





// ##   ##  #####  #####  
// # ### #  #   #  #   #  
// #  #  #  #####  #####  
// #     #  #   #  #      
// #     #  #   #  #   



template<
    class Key,
    class T,
    class Compare = ft::less<Key>,
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

	typedef ft::map_iterator<key_type, mapped_type, value_type>			iterator;
	typedef ft::map_iterator<key_type, mapped_type, const value_type>	const_iterator;
	typedef	ft::reverse_iterator<iterator>								reverse_iterator;
	typedef	ft::reverse_iterator<const_iterator>						const_reverse_iterator;

	private:
	typedef	struct nodee<key_type, mapped_type>		node;
	typedef	node*	node_ptr;
	
	bst<key_type, mapped_type, key_compare, allocator_type>		tree_;
	allocator_type									alloc_;
	key_compare										comp;
	
	public:
	class value_compare : ft::binary_function<value_type, value_type, bool>
	{
		friend class map<Key, T, Compare, Allocator>;
	protected:
		Compare comp;
		value_compare (Compare c) : comp(c) {}
	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator() (const value_type& x, const value_type& y) const
		{
		  return comp(x.first, y.first);
		}
	};

	//Constructor
	explicit map(const key_compare& com = key_compare(), const allocator_type &alloc = allocator_type())
	: tree_(com, alloc), alloc_(alloc), comp(key_compare())
	{}

	template<class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare& com = key_compare(), const allocator_type &alloc = allocator_type())
	: tree_(com, alloc), alloc_(alloc), comp(key_compare())
	{
		for (; first != last; first++)
			tree_.insert(*first);
	}
	
	map(const map& ref) : tree_(ref.tree_), alloc_(ref.alloc_), comp(key_compare())
	{}

	map&	operator=(const map& ref)
	{
		if (this == &ref)
			return *this;
		tree_ = ref.tree_;
		alloc_ = ref.alloc_;
		return *this;
	}


	//Destructor
	~map(){}
	
	
	//Iterator
	iterator begin()
	{
		node* x;
		if ( (x = tree_.min()) )
			return iterator(x, tree_.get_end());
		return iterator(tree_.get_end(), tree_.get_end());
	}
	const_iterator begin() const
	{
		node* x;
		if ( (x = tree_.min()) )
			return const_iterator(x, tree_.get_end());
		return const_iterator(tree_.get_end(), tree_.get_end());
	}

	iterator end()
	{
		return iterator(tree_.get_end(), tree_.get_end());
	}
	const_iterator end() const
	{
		return const_iterator(tree_.get_end(), tree_.get_end());
	}


	//Reverse Iterator
	reverse_iterator rbegin()
	{
		return reverse_iterator(end());
	}
	reverse_iterator rend()
	{
		return reverse_iterator(begin());
	}

	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(end());
	}
	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(begin());
	}


	//Capacity
	bool empty() const
	{ return size() == 0; }

	size_type	size() const
	{ return tree_.get_size(); }

	size_type	max_size() const
	{ return tree_.max_size(); }


	//Access
	mapped_type&	operator[](const key_type& k)
	{
		node* x;
		if ( (x = tree_.search(k)) )
			return x->pair.second;
		else
		{
			ft::pair<key_type, mapped_type> pairr;
			pairr.first = k;
			return (tree_.insert(pairr))->pair.second;
		}
	}

	mapped_type&	at(const key_type& k)
	{
		node* x;
		if ( (x = tree_.search(k)) )
			return x->pair.second;
		else
			throw(std::out_of_range("ft::map::at"));
	}


	//Modifiers
	ft::pair<iterator, bool> insert(const value_type& val)
	{
		node *x;

		if ( (x = tree_.search(val.first)) )
			return ft::make_pair<iterator, bool>(iterator(x, tree_.get_end()), false);
		return ft::make_pair<iterator, bool>(iterator(tree_.insert(val), tree_.get_end()), true);
	}

	iterator	insert(iterator position, const value_type& val)
	{
		(void)position;
		return iterator(tree_.insert(val), tree_.get_end());
	}

	template<class InputIterator>
	void	insert(InputIterator first, InputIterator last)
	{
		// while( first != last )
		// 	tree_.insert(*first++);
		while( first != last )
		{
			tree_.insert(*first);
			++first;
		}	

	}


	void	erase(iterator position)
	{
		tree_.erase((*position).first);
	}

	size_type	erase(const key_type& k)
	{
		size_type i = size();
		tree_.erase(k);
		return i - size();
	}

	void	erase(iterator first, iterator last)
	{
		while (first != last)
			erase((*(first++)).first);
	}

	void	swap(map& ref)
	{
		node*		root_tmp;
		node*		end_tmp;
		size_type	size_tmp;

		root_tmp = tree_.get_root();
		size_tmp = tree_.get_size();
		end_tmp = tree_.get_end();

		tree_.set_root(ref.tree_.get_root());
		tree_.set_end(ref.tree_.get_end());
		tree_.set_size(ref.tree_.get_size());

		ref.tree_.set_root(root_tmp);
		ref.tree_.set_end(end_tmp);
		ref.tree_.set_size(size_tmp);
	}

	void	clear()
	{ tree_.clear(); }


	//Observers
	key_compare key_comp() const
	{
		return comp;
	}

	value_compare	value_comp()
	{
		return value_compare(comp);
	}

	// Operations
	iterator	find(const key_type& k)
	{
		if (count(k))
			return iterator(tree_.search(k), tree_.get_end());
		return (end());
	}

	const_iterator find (const key_type& k) const
	{
		if (count(k))
			return const_iterator(search(k), tree_.get_end());
		return (end());
	}

	size_type count (const key_type& k) const
	{
		
		if(tree_.search(k))
			return 1;
		return 0;
	}

	iterator lower_bound (const key_type& k)
	{
		node*	tmp;

		tmp = tree_.min();
		while (tmp)
		{
			if ( comp(tmp->pair.first, k) == false )
				return (iterator(tmp, tree_.get_end()));
			tmp = tree_.successor(tmp);
		}
		return (end());

	}
	const_iterator lower_bound (const key_type& k) const
	{
		node*	tmp;

		tmp = tree_.min();
		while (tmp)
		{
			if ( comp(tmp->pair.first, k) == false )
				return (const_iterator(tmp, tree_.get_end()));
			tmp = tree_.successor(tmp);
		}
		return (const_iterator(end()));
	}

	iterator upper_bound (const key_type& k)
	{
		node*	tmp;

		tmp = tree_.min();
		while (tmp)
		{
			if ( comp(k, tmp->pair.first) == true )
				return (iterator(tmp, tree_.get_end()));
			tmp = tree_.successor(tmp);
		}
		return (end());

	}
	const_iterator upper_bound (const key_type& k) const
	{
		node*	tmp;

		tmp = tree_.min();
		while (tmp)
		{
			if ( comp(k, tmp->pair.first) == true )
				return (const_iterator(tmp, tree_.get_end()));
			tmp = tree_.successor(tmp);
		}
		return (const_iterator(end()));
	}

	pair<const_iterator,const_iterator> equal_range (const key_type& k) const
	{
		return ft::make_pair(lower_bound(k), upper_bound(k));
	}

	pair<iterator,iterator>		equal_range (const key_type& k)
	{
		return ft::make_pair(lower_bound(k), upper_bound(k));
	}


	// Allocator
	allocator_type	get_allocator()
	{ return alloc_; }

	bool operator==(const map& ref)
	{
		iterator 	ref_it = ref.begin();
		iterator	it = this->begin();

		while (ref_it != ref.end() || it != this->end())
		{
			if ((*it) != (*ref_it))
				return false;
			it++;
			ref_it++;
		}
		if (ref_it == ref.end() && it == this->end())
			return true;
		return false;
	}

};

template< class Key, class T, class Compare, class Alloc >
bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
{
		typename ft::map<Key, T, Compare>::iterator 	lhs_it = lhs.begin();
		typename ft::map<Key, T, Compare>::iterator	rhs_it = rhs.begin();

		while (lhs_it != lhs.end() || rhs_it != rhs.end())
		{
			if ((*rhs_it) != (*lhs_it))
				return false;
			rhs_it++;
			lhs_it++;
		}
		if (lhs_it == lhs.end() && rhs_it == rhs.end())
			return true;
		return false;
}

template< class Key, class T, class Compare, class Alloc >
bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
{ return !(lhs == rhs); }

template< class Key, class T, class Compare, class Alloc >
bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template< class Key, class T, class Compare, class Alloc >
bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
{
	return !(lhs < rhs);
}

template< class Key, class T, class Compare, class Alloc >
bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
{
	return rhs < lhs;
}

template< class Key, class T, class Compare, class Alloc >
bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
{
	return !(rhs < lhs);
}


template< class Key, class T, class Compare, class Alloc >
void swap(ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs)
{ lhs.swap(rhs); }





// #####  #####  #####  #####  #####  #####  #####  #####  
//   #      #    #      #   #  #   #    #    #   #  #   #  
//   #      #    #####  #####  #####    #    #   #  #####  
//   #      #    #      # #    #   #    #    #   #  # #    
// #####    #    #####  #  #   #   #    #    #####  #  # 

template<class Key, class T, class Value_Type>
class map_iterator
{
	public:
	typedef typename iterator<bidirectional_iterator_tag, Value_Type>::value_type			value_type;
	typedef typename iterator<bidirectional_iterator_tag, Value_Type>::difference_type		difference_type;
	typedef typename iterator<bidirectional_iterator_tag, Value_Type>::pointer				pointer;
	typedef typename iterator<bidirectional_iterator_tag, Value_Type>::reference			reference;
	typedef typename iterator<bidirectional_iterator_tag, Value_Type>::iterator_category	iterator_category;
	
	private:
	typedef	struct nodee<Key, T>		node;
	typedef	node*	node_ptr;
	
	node*	ptr;
	node*	end;
	
	public:
	map_iterator() : ptr(0), end(0)
	{}

	map_iterator(const map_iterator& ref) : ptr(ref.ptr), end(ref.end)
	{}

	map_iterator(const node_ptr& p, const node_ptr& en) 
	: ptr(p), end(en)
	{}

	template<class K, class M, class V>
	map_iterator(const map_iterator<K, M, V>& ref) : ptr(ref.base()), end(ref.get_end())
	{}

	map_iterator&	operator=(const map_iterator& ref)
	{
		if (this == &ref)
			return *this;
		ptr = ref.ptr;
		end = ref.end;
		return *this;
	}

	~map_iterator(){}

	value_type&	operator*() const
	{
		if (ptr == end)
			return (bst<Key, T, ft::less<Key>,  std::allocator<int> >::max(end->right))->pair;
		return ptr->pair;
	}

	value_type*	operator->() const
	{
		return &(ptr->pair);
	}

	map_iterator& operator++()
	{
		node* tmp;

		if ( ptr != end && (tmp = bst<Key, T, ft::less<Key>,  std::allocator<int> >::successor(ptr)) )
			ptr = tmp;
		else
			ptr = end;
		
		return *this;
	}

	map_iterator operator++(int)
	{
		map_iterator tmp = *this;
		operator++();
		return tmp;
	}

	map_iterator& operator--()
	{
		node* tmp;
		if ( ptr != end && (tmp = bst<Key, T, ft::less<Key>,  std::allocator<int> >::predecessor(ptr)) )
			ptr = tmp;
		else
			ptr = bst<Key, T, ft::less<Key>,  std::allocator<int> >::max(end->right);
	return *this;
	}

	map_iterator operator--(int)
	{
		map_iterator tmp = *this;
		operator--();
		return tmp;
	}

	node*	base() const
	{ return ptr; }
	node*	get_end() const
	{ return end; }
};

template<class Key, class T> 
bool operator!=(const map_iterator<Key, T, ft::pair<const Key, T> >&a, const map_iterator<Key, T, ft::pair<const Key, T> >&b)
{
	return a.base() != b.base();
}

template<class Key, class T> 
bool operator==(const map_iterator<Key, T, ft::pair<const Key, T> >&a, const map_iterator<Key, T, ft::pair<const Key, T> >&b)
{
	return a.base() == b.base();
}

template<class Key, class T> 
bool operator!=(const map_iterator<Key, T, const ft::pair<const Key, T> >&a, const map_iterator<Key, T, ft::pair<const Key, T> >&b)
{
	return a.base() != b.base();
}

template<class Key, class T> 
bool operator==(const map_iterator<Key, T, const ft::pair<const Key, T> >&a, const map_iterator<Key, T, ft::pair<const Key, T> >&b)
{
	return a.base() == b.base();
}

template<class Key, class T> 
bool operator!=(const map_iterator<Key, T, ft::pair<const Key, T> >&a, const map_iterator<Key, T, const ft::pair<const Key, T> >&b)
{
	return a.base() != b.base();
}

template<class Key, class T> 
bool operator==(const map_iterator<Key, T, ft::pair<const Key, T> >&a, const map_iterator<Key, T, const ft::pair<const Key, T> >&b)
{
	return a.base() == b.base();
}

template<class Key, class T> 
bool operator!=(const map_iterator<Key, T, const ft::pair<const Key, T> >&a, const map_iterator<Key, T, const ft::pair<const Key, T> >&b)
{
	return a.base() != b.base();
}

template<class Key, class T> 
bool operator==(const map_iterator<Key, T, const ft::pair<const Key, T> >&a, const map_iterator<Key, T, const ft::pair<const Key, T> >&b)
{
	return a.base() == b.base();
}





}


#endif