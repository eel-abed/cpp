#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <limits>

class Span
{
private:
	unsigned int _maxSize;
	std::vector<int> _numbers;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);

	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			if (_numbers.size() >= _maxSize)
				throw SpanFullException();
			_numbers.push_back(*begin);
			++begin;
		}
	}

	int shortestSpan() const;
	int longestSpan() const;

	unsigned int getSize() const;
	unsigned int getMaxSize() const;

	class SpanFullException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif
