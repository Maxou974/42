#include "Span.hpp"

Span::Span() : _span_size(0), _span(0)
{
}

Span::Span(unsigned int N) : _span_size(N), _span(0)
{
}

Span::~Span()
{
}

Span::Span(const Span &ref) : _span_size(ref._span_size), _span(ref._span)
{
}

Span&	Span::operator=(const Span &ref)
{
	if (this == &ref)
		return *this;
	_span = ref._span;
	return *this;
}

void	Span::addNumber(int i)
{
	if (_span.size() == _span_size)
		throw SpanException();
	else
		_span.push_back(i);
}

void	Span::addPlage(int *start, int *end)
{
	if (std::distance(start, end) + _span.size() > _span_size)
		throw SpanException();
	else
		while (start != end)
			_span.push_back(*start++);
}

void	Span::printSpan()
{
	for(unsigned int i = 0; i < _span_size; i++)
		std::cout << _span[i] << " ";
	std::cout << '\n';
}

unsigned int	Span::longestSpan()
{
	if (_span.size() < 2)
		throw SpanException();
	int ptrmin = *(std::min_element(_span.begin(), _span.end()));
	int ptrmax = *(std::max_element(_span.begin(), _span.end()));
	return (ptrmax - ptrmin);
}

unsigned int	Span::shortestSpan()
{
	if (_span.size() < 2)
		throw SpanException();
	const Span	copy = Span(*this);

	std::sort(_span.begin(), _span.end());
	
	unsigned int	gap = _span[1] - _span[0];

	for(unsigned int i = 0; i < _span.size() - 1; i++)
	{
		if (static_cast<unsigned int>(_span[i + 1] - _span[i]) < gap)
			gap = static_cast<unsigned int>(_span[i + 1] - _span[i]);
	}
	*this = copy;
	return gap;
}