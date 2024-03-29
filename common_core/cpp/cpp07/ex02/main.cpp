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

	Array<char> str(3);

	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';

	print(str);

	Array<char> co = str;
	const Array<char> c(str);

	print(co);
	print(c);

	Array<std::string> lala(3);
	// Array<std::string> lala(4);

	lala[0] = "hELLO";
	lala[1] = " iM ";
	lala[2] = " mAXIME";

	print(lala);
	const Array<std::string> c_lala(lala);

	try
	{
		std::cout << c_lala[1] << '\n';
		std::cout << c_lala[3] << '\n';
		std::cout << "HEYYYY\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

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