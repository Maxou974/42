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
	Data data;

	std::cout << &data << '\n';
	std::cout << deserialize(serialize(&data)) << '\n';

}