#include "Span.hpp"

Span::Span() : _span_size(0)
{
	_span = NULL;
	_n = 0;
}

Span::Span(unsigned int N) : _span_size(N)
{
	_span = new int[N];
	_n = 0;
}

Span::~Span()
{
	delete []_span;
}

Span::Span(const Span &ref) : _span_size(ref._span_size)
{
	_span = new int[ref._span_size];
	_n = 0;
	while (_n < ref._n)
	{
		_span[_n] = ref._span[_n];
		_n++;
	}
}

Span&	Span::operator=(const Span &ref)
{
	if (this == &ref)
		return *this;
	delete []_span;
	_span = new int[ref._span_size];
	_n = 0;
	while (_n < ref._n)
	{
		_span[_n] = ref._span[_n];
		_n++;
	}
	return *this;
}

void	Span::addNumber(int i)
{
	if (_n == _span_size)
	{
		throw SpanException();
	}
	else
	{
		_span[_n] = i;
		_n++;
	}
}

void	Span::addPlage(int *start, int *end)
{
	while (start != end)
	{
		if (_n == _span_size)
		{
			throw SpanException();
		}
		else
		{
			_span[_n] = *start;
			_n++;
			start += 1;
		}
	}
}

void	Span::printSpan()
{
	for(unsigned int i = 0; i < _n; i++)
		std::cout << _span[i] << " ";
	std::cout << '\n';
}

unsigned int	Span::longestSpan()
{
	if (_n < 2)
		throw SpanException();
	int* ptrmin = std::min_element(_span, _span + _n);
	int* ptrmax = std::max_element(_span, _span + _n);
	return (*ptrmax - *ptrmin);
}

unsigned int	Span::shortestSpan()
{
	if (_n < 2)
		throw SpanException();
	Span	copy = Span(*this);
	std::sort(copy._span, copy._span + copy._n);
	unsigned int	gap = *(copy._span + 1) - *copy._span;
	for(unsigned int i = 0; i < copy._n - 1; i++)
	{
		if (static_cast<unsigned int>(copy._span[i + 1] - copy._span[i]) < gap)
			gap = static_cast<unsigned int>(copy._span[i + 1] - copy._span[i]);
	}
	return gap;
}