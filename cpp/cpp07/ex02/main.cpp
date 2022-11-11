#include "Array.hpp"

template<typename T>
void	print(Array<T>ar)
{
	for (size_t i = 0; i < ar.size(); i++)
		std::cout << ar[i] << ' ';
	std::cout << '\n';
}


int main()
{
	Array<int> ar(5);
	Array<int> copy(2);

	for (int i = 0; i < 5; i++)
		ar[i] = i;

	print(ar);
	copy = ar;
	ar[2] = 435;
	print(ar);
	print(copy);

	ar = ar;
	print(ar);

	Array<char> str(3);

	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';

	print(str);

	Array<char> co = str;
	Array<char> c(str);

	print(co);
	print(c);
}

// #include <iostream>
// #include <cstdlib>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }