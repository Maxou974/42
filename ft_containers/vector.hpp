#include <memory>
#include <vector>

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
		/*todo
		iterator
		const_iterator
		reverse_iterator
		const_reverse_iterator
		difference_type
		*/
		typedef	size_t	size_type;

		private:
		pointer		vect_;
		size_type	size_;
		size_type	capacity_;
		allocator_type alloc_;

		public:
		//Constructor
		explicit vector(const allocator_type& alloc = allocator_type())
		: vect_(0), size_(capacity_ = 0), alloc_(alloc) {}
		
		explicit vector(size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
		: alloc_(alloc)
		{
			vect_ = alloc_.allocate(size_ = capacity_ = n);
			for (size_type i = 0; i < size_; i++)
				alloc_.construct(&vect_[i], val);
		}

		//todo constructor with iterator range

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
			if (n < size_)
			{
				for (; size_ > n; size_--)
					alloc_.destroy(&vect_[size_ - 1]);
			}
			else
			{
				if (n > capacity_)
				{
					vector tmp = *this;
					if (n < 2 * size_)
						tmp.capacity_ = 2 * size_;
					else
						tmp.capacity_ = n;
					*this = tmp;
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
				size_type tmp = size_;
				resize(n);
				size_ = tmp;
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
		{ return at(n); }


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
		void	clear()
		{
			for (; size_ > 0; size_--)
				alloc_.destroy(&vect_[size_ - 1]);
		}

		
		void	push_back(const value_type& val)
		{(void)val;
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
	};
}