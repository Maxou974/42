#include "Span.hpp"

Span::Span() : _span_size(0)
{
}

Span::Span(unsigned int N) : _span_size(N)
{
}

Span::~Span()
{
}

Span::Span(const Span &ref) : _span_size(ref._span_size)
{
	_span = ref._span;
}

Span&	Span::operator=(const Span &ref)
{
	_span = ref._span;
	return *this;
}

void	Span::addNumber(int i)
{
	if (_span.size() == _span_size)
		throw SpanException();
	else
		_span[_n] = i;
}

void	Span::addPlage(int *start, int *end)
{
	if (std::distance(start, end) + _span.size() > _span_size)
		throw SpanException();
	else
		while (start != end)
		{
			_span.push_back(*start);
			start++;
		}
	_span.push_back(*start);
}

void	Span::printSpan()
{
	for(unsigned int i = 0; i < _span_size; i++)
		std::cout << _span[i] << " ";
	std::cout << '\n';
}

unsigned int	Span::longestSpan()
{
	if (_n < 2)
		throw SpanException();
	int* ptrmin = std::min_element(_span, _span + _span.size());
	int* ptrmax = std::max_element(_span, _span + _span.size());
	return (*ptrmax - *ptrmin);
}

unsigned int	Span::shortestSpan()
{
	if (_n < 2)
		throw SpanException();
	Span	copy = Span(*this);
	std::sort(copy._span, copy._span + copy._n);
	unsigned int	gap = *(copy._span + 1) - *copy._span;
	for(unsigned int i = 0; i < copy._span.size() - 1; i++)
	{
		if (static_cast<unsigned int>(copy._span[i + 1] - copy._span[i]) < gap)
			gap = static_cast<unsigned int>(copy._span[i + 1] - copy._span[i]);
	}
	return gap;
}