#include "Span.hpp"

int main()
{
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(15);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try{
		sp.addNumber(142);
	}
	catch(std::exception & e)
	{
		std::cout << e.what();
	}

}
	std::cout << '\n';

	Span s(10000);
	for (int i = 0; i < 10000; i++)
		s.addNumber(i);

	try {
		std::cout << s.longestSpan() << '\n';
		std::cout << s.shortestSpan() << '\n';
	}
	catch (SpanException &e)
	{ std::cout << e.what(); }
	std::cout << '\n';

	Span s1(10);
	Span s2(10);
	int t[10] = { 5,2,4,1,7,8,3,9,10,6};
	int	t2[11] = {1,2,3,4,5,6,7,8,9,10,11};

	s1.addPlage(t, t+10);
	s1.printSpan();

	try {
		std::cout << s1.longestSpan() << '\n';
		std::cout << s1.shortestSpan() << '\n';
		s1.printSpan();
		//s1.addNumber(124);
		s2.addPlage(t2, t2+11);
		s2.printSpan();
		std::cout << "TEST\n";
	}
	catch (SpanException &e)
	{ std::cout << e.what(); }
}