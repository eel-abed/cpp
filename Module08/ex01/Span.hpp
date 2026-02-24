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
	// Orthodox Canonical Form
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	// Member functions
	void addNumber(int number);

	// Template function to add range of iterators
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

	// Getters
	unsigned int getSize() const;
	unsigned int getMaxSize() const;

	// Exception classes
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
