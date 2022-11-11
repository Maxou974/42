#include <iostream>
#include <cstdint>
#include "Data.hpp"

uintptr_t	serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main()
{
	Data data = Data();

	uintptr_t ptr2 = serialize(&data);
	Data	*tmp = deserialize(ptr2);
	std::cout << reinterpret_cast<void *>(ptr2) << '\n' << tmp << '\n';

	uintptr_t uintptr = serialize(&data);
	std::cout << &data << '\n' << deserialize(uintptr) << '\n';
}