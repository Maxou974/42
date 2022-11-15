#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <utility>
#include <algorithm>

class Span {
	unsigned int		_n;
	unsigned int	_span_size;
	int					*_span;
public:
	Span();
	Span(unsigned int);
	~Span();
	Span(const Span &);
	Span&	operator=(const Span &);
	void	addNumber(int);
	void	addPlage(int*, int*);
	void	printSpan();
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
};

class SpanException : public std::exception{

	public:
const char *what (){
	return "Span size is not large enough\n";
}
};

#endif