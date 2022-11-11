#ifndef	ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template<class T> class Array
{
	T* array;
	size_t siz;
public:
	Array(){ array = NULL; siz = 0; }
	Array(unsigned int si) 
	{ 
		array = new T[siz = si]; 
		for (size_t i = 0; i < siz; i++)
			array[i] = 0;
	}
	Array(const Array &ref)
	{
		array = new T[siz = ref.siz];
		for (size_t i = 0; i < siz; i++)
			array[i] = ref.array[i];
	}
	Array& operator=(const Array &ref)
	{
		if (this == &ref)
			return *this;
		delete[] array;
		array = new T[siz = ref.siz];
		for (size_t i = 0; i < siz; i++)
			array[i] = ref.array[i];
		return *this;
	}
	~Array(){ delete[] array; }

	T& operator[](size_t i)
	{
		if (i >= siz || i < 0)
			throw std::overflow_error("Array index overflow\n");
		return array[i];
	}

	size_t	size()const{
		return siz;
	}
};

#endif