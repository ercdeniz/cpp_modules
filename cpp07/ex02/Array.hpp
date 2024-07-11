#pragma once

#include <iostream>

// COLORS
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define ITALIC_PURPLE "\033[2;3;95m"
#define RESET "\033[0m"

template <typename T>
class Array
{
	private:
		T* _array;
		size_t _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		~Array(void);
		Array& operator=(const Array& other);
		T&	operator[](const unsigned int index);
		const size_t& size() const;
		class OutOfBoundsException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

template< typename T >
std::ostream& operator<<(std::ostream& out, Array<T>& arr);

#include "Array.tpp"
