#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstring>

template <typename T>
class Array
{
private:
	T *_data;
	unsigned int _size;

public:
	// Default constructor: empty array
	Array() : _data(NULL), _size(0)
	{
	}

	// Constructor with unsigned int: creates array of n elements (default initialized)
	Array(unsigned int n) : _data(NULL), _size(n)
	{
		if (n > 0)
		{
			_data = new T[n]();
		}
	}

	// Copy constructor: deep copy
	Array(const Array &other) : _data(NULL), _size(other._size)
	{
		if (_size > 0)
		{
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
			{
				_data[i] = other._data[i];
			}
		}
	}

	// Assignment operator: deep copy
	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			// Clean up existing data
			delete[] _data;
			_data = NULL;
			_size = 0;

			// Copy new data
			_size = other._size;
			if (_size > 0)
			{
				_data = new T[_size];
				for (unsigned int i = 0; i < _size; ++i)
				{
					_data[i] = other._data[i];
				}
			}
		}
		return (*this);
	}

	// Destructor
	~Array()
	{
		delete[] _data;
	}

	// Subscript operator with bounds checking
	T &operator[](unsigned int index)
	{
		if (index >= _size)
		{
			throw std::out_of_range("Array index out of bounds");
		}
		return (_data[index]);
	}

	// Const subscript operator with bounds checking
	const T &operator[](unsigned int index) const
	{
		if (index >= _size)
		{
			throw std::out_of_range("Array index out of bounds");
		}
		return (_data[index]);
	}

	// Size member function
	unsigned int size() const
	{
		return (_size);
	}
};

#endif
