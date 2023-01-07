#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <memory>
#include "iterator.hpp"
#include "type_traits.hpp"
#include "compare.hpp"

namespace ft{
	
	template < typename T, typename Alloc = std::allocator<T> >
	class vector
	{
		public:
		typedef T		value_type;
		typedef Alloc	allocator_type;

		typedef	typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef ft::random_access_iterator<value_type> 			iterator;
		typedef ft::random_access_iterator<const value_type>	const_iterator;
		typedef ft::random_access_iterator_tag					iterator_category;
		typedef	typename ft::iterator<random_access_iterator_tag, value_type>::difference_type	difference_type;
		typedef ft::reverse_iterator<iterator>	reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		typedef	size_t	size_type;

		private:
		pointer		vect_;
		size_type	size_;
		size_type	capacity_;
		allocator_type alloc_;

		public:
		//Constructor
		explicit vector(const allocator_type& alloc = allocator_type())
		: vect_(0), size_(capacity_ = 0), alloc_(alloc)
		{}
		
		explicit vector(size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
		: alloc_(alloc)
		{
			vect_ = alloc_.allocate(size_ = capacity_ = n);
			for (size_type i = 0; i < size_; i++)
				alloc_.construct(&vect_[i], val);
		}

		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()
				,typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0 ) : alloc_(alloc)
		{
			typename ft::iterator_traits<InputIterator>::difference_type n = last - first;
			vect_ = alloc_.allocate(size_ = capacity_ = n);
			for (size_type i = 0; first < last; first++, i++)
				alloc_.construct(&vect_[i], *first);
		}

		vector(const vector& ref) : alloc_(ref.alloc_)
		{
			size_ = ref.size_;
			vect_ = alloc_.allocate(capacity_ = ref.capacity_);
			for (size_type i = 0; i < size_; i++)
				alloc_.construct(&vect_[i], ref.vect_[i]);
		}

		vector&	operator=(const vector& ref)
		{
			if (ref.vect_ == this->vect_)
				return *this;
			clear(); alloc_.deallocate(vect_, capacity_);
			alloc_ = ref.alloc_; size_ = ref.size_;
			vect_ = alloc_.allocate(capacity_ = ref.capacity_);
			for (size_type i = 0; i < size_; i++)
				alloc_.construct(&vect_[i], ref.vect_[i]);
			return *this;
		}


		//Destructor
		~vector()
		{ clear(); alloc_.deallocate(vect_, capacity_); }


		//Iterator
		iterator	begin()
		{ return (&vect_[0]); }
		const_iterator	begin() const
		{ return (&vect_[0]); }

		iterator	end()
		{ return (&vect_[size_]); }
		const_iterator	end() const
		{ return (&vect_[size_]); }

		reverse_iterator	rbegin()
		{ return (&vect_[size_]); }
		const_reverse_iterator	rbegin() const
		{ return (&vect_[size_]); }

		reverse_iterator	rend()
		{ return (&vect_[0]); }
		const_reverse_iterator	rend() const
		{ return (&vect_[0]); }


		//Capacity
		size_type size(void) const
		{ return size_; }

		
		size_type capacity(void) const
		{ return capacity_; }

		
		size_type max_size(void) const
		{ return allocator_type().max_size(); }

		
		void	resize(size_type n, value_type val = value_type())
		{
			if (n > allocator_type().max_size())
				throw(std::length_error("ft::vector::resize"));
			if (n <= size_)
			{
				for (; size_ > n; size_--)
					alloc_.destroy(&vect_[size_ - 1]);
			}
			else
			{
				if (n > capacity_)
				{
					reserve(n);
				}
				for (; size_ < n; size_++)
					alloc_.construct(&vect_[size_], val);
			}
		}


		bool	empty() const
		{ return (size_ == 0); }


		void	reserve(size_type n)
		{
			if (n > allocator_type().max_size())
				throw(std::length_error("ft::vector::reserve"));
			else if (n > capacity_)
			{
				pointer	ptr;
				size_type	si = size_, ca = capacity_;
				if (n < 2 * si)
					ptr = alloc_.allocate(capacity_ = 2 * si);
				else
					ptr = alloc_.allocate(capacity_ = n);
				for (size_type i = 0; i < si; i++)
					alloc_.construct(&ptr[i], vect_[i]);

				clear(); alloc_.deallocate(vect_, ca);
	
				vect_ = ptr;
				size_ = si;

				if (n < 2 * si)
					capacity_ = 2 * si;
				else
					capacity_ = n;
			}
		}


		//Element access
		value_type&	operator[](int index)
		{ return vect_[index]; }

		const value_type&	operator[](int index) const
		{ return vect_[index]; }


		reference	at(size_type n)
		{
			if (n >= size_)
				throw(std::out_of_range("ft::vector::at"));
			return vect_[n];
		}

		const_reference	at(size_type n) const
		{
			if (n >= size_)
				throw(std::out_of_range("ft::vector::at"));
			return vect_[n];
		}


		reference	front()
		{ return at(0); }

		const_reference	front() const
		{ return at(0); }


		reference	back()
		{ return at(size_ - 1); }

		const_reference	back() const
		{ return at(size_ - 1); }


		value_type*	data()
		{
			if (size_ == 0)
				return 0;
			return vect_;
		}

		const value_type*	data() const
		{
			if (size_ == 0)
				return 0;
			return vect_;
		}


		//Modifiers
		iterator erase (iterator position)
		{
			while (position >= end())
				position--;
			alloc_.destroy(&(*position));
			for (iterator pos = position+1; pos < end(); pos++)
			{
				value_type	tmp = *pos;
				alloc_.destroy(&(*(pos)));
				alloc_.construct(&(*(pos - 1)), tmp);
			}
			size_--;
			if (position == end())
				return position - 1;
			return position;
		}


		iterator	erase(iterator first, iterator last)
		{
			if (first >= last)
				return last;

			size_type nbr = 0;
			iterator beg = first;
			while (nbr < size_ && beg < last)
			{ beg++; nbr++; }

			for (iterator pos = first; pos < last; pos++)
			{
				alloc_.destroy(&(*pos));
				alloc_.construct(&(*pos), *(pos + nbr));
				alloc_.destroy(&(*(pos + nbr)));
			}
			for (iterator pos = first + nbr; pos < end() - nbr; pos++)
			{
				alloc_.construct(&(*pos), *(pos + nbr));
				alloc_.destroy(&(*(pos + nbr)));
			}
			size_ -= nbr;
			return last;
		}


		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
		{
			typename	ft::iterator_traits<InputIterator>::difference_type n = last - first;
			if (static_cast<size_type>(n) > capacity_)
				resize(n);
			clear();
			for (; first < last;)
				alloc_.construct(&vect_[size_++], *(first++));
		}

		void assign (size_type n, const value_type& val)
		{ clear(); resize(n, val); }


		iterator insert (iterator position, const value_type& val)
		{ 
			size_type nbr = 0;
			iterator beg = begin();
			while (nbr < size_ && beg.base() < position.base())
			{ beg++; nbr++; }

			
			insert(position, 1, val);
			
			position = &vect_[nbr]; 
			return (position);
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			size_type nbr = 0;
			iterator beg = begin();
			while (nbr < size_ && beg.base() < position.base())
			{ beg++; nbr++; }
			
			reserve(n + size_);

			position = &vect_[nbr];
			
			for (size_type i = size_ - 1; &vect_[i] >= position.base(); i--)
			{
				value_type tmp = vect_[i];
				if (i + n <= size_ - 1)
					alloc_.destroy(&vect_[i + n]);
				alloc_.construct(&vect_[i + n], tmp);
				if (i == 0)
					break;
			}

			for (size_type i = 0; i < n; i++, position++)
			{
				if (&(*position) < end().base())
					alloc_.destroy(&(*position));
				alloc_.construct(&(*position), val);
			}
			size_ += n;
		}

		template <class InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
		{
			difference_type n = last - first;
			difference_type nbr = position - begin();

			// std::cout << first_dist << " " << last_dist << '\n'; 
		//	vector<value_type>	tmp_vec;
			// iterator	f = first;
			// iterator	l = last;
			if (n + size_ > capacity_)
			{
				// tmp_vec.assign(first, last);
				// f = tmp_vec.begin();
				// l = tmp_vec.end();
				reserve(n + size_);
			 	position = &vect_[nbr];
			}

			for (size_type i = size_ - 1; &vect_[i] >= &(*position); i--)
			{
				if (i + n >= size_)
					alloc_.construct(&vect_[i + n], vect_[i]);
				else
					vect_[i + n] = vect_[i];	
			}

			iterator en = end();
			for (; first < last; first++, position++)
				*position = *first;
			size_ += n;
		}


		void	clear()
		{
			for (; size_ > 0; size_--)
				alloc_.destroy(&vect_[size_ - 1]);
		}

		
		void	push_back(const value_type& val)
		{
			if (size_ == capacity_)
				reserve(capacity_ + 1);
			alloc_.construct(&vect_[size_++], val);
		}


		void	pop_back()
		{
			if (size_ != 0)
				alloc_.destroy(&vect_[--size_]);
		}


		void	swap(vector& ref)
		{
			size_type	tmp_size = ref.size_;
			size_type	tmp_capacity = ref.capacity_;
			pointer		tmp_vect = ref.vect_;
			allocator_type tmp_alloc = ref.alloc_;

			ref.size_ = size_;
			ref.capacity_ = capacity_;
			ref.vect_ = vect_;
			ref.alloc_ = alloc_;

			size_ = tmp_size;
			capacity_ = tmp_capacity;
			vect_ = tmp_vect;
			alloc_ = tmp_alloc;
		}


		allocator_type get_allocator() const
		{ return alloc_; }
	};

template <class T, class Alloc>
bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class T, class Alloc>
bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator< (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return !(lhs < rhs);
}

template <class T, class Alloc>
bool operator> (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return rhs < lhs;
}

template <class T, class Alloc>
bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return !(rhs < lhs);
}

template <class T, class Alloc>
void	swap(ft::vector<T, Alloc>& l, ft::vector<T, Alloc>& r)
{
	l.swap(r);
}


}


#endif