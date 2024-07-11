#pragma once 

template <typename T>
Array<T>::Array(void) : _array(0), _size(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_array = new T[n];
	_size = n;
	std::cout << CYAN << "Parametric constructor called" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T>& copy)
{
	_array = new T[copy.size()];
	_size = copy.size();
	std::cout << MAGENTA << "Copy constructor called" << RESET << std::endl;
	for (unsigned int i = 0; i < copy.size(); i++)
		this->_array[i] = copy._array[i];
}

template <typename T>
Array<T>::~Array(void)
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
	delete[] this->_array;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& other)
{
	std::cout << MAGENTA << "Assignation operator called" << RESET << std::endl;
	if (this != &other)
	{
		delete[] this->_array;
		this->_array = new T[other.size()];
		this->_size = other.size();
		for (unsigned int i = 0; i < other.size(); i++)
			this->_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](const unsigned int index)
{
	if (index >= this->_size)
		throw Array<T>::OutOfBoundsException();
	return (this->_array[index]);
}

template <typename T>
const size_t& Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return (YELLOW "index out of bounds" RESET);
}

template< typename T >
std::ostream& operator<<(std::ostream& out, Array<T>& arr)
{
    for (size_t i = 0; i < arr.size(); i++)
        out << "[" << ITALIC_PURPLE << arr[i] << RESET << "]";
    return out;
}