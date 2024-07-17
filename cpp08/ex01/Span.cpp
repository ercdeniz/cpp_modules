#include "Span.hpp"

Span::Span() : _N(0), _count(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Span::Span(const unsigned int N) : _N(N), _count(0)
{
	std::cout << GREEN << "Parameter constructor called" << RESET << std::endl;
}

Span::Span(const Span &copy)
{
	std::cout << MAGENTA << "Copy constructor called" << RESET << std::endl;
	*this = copy;
}

Span::~Span()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

Span &Span::operator=(const Span &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_N = other._N;
		this->_count = other._count;
		this->_arr = other._arr;
	}
	return *this;
}

const std::vector<int> &Span::getArr(void) const
{
	return _arr;
}

int Span::getRandomNumber(void) const
{
	return (rand() % MAXRAND);
}

void Span::addNumber(const int number)
{
	if (_count >= _N)
		throw FullArrayException();
	_arr.push_back(number);
	_count++;
}

void Span::sortArray()
{
	_sortedArr = _arr;
	std::sort(_sortedArr.begin(), _sortedArr.end());
}

int Span::shortestSpan(void)
{
	if (_count < 2)
		throw SmallSizeException();
	sortArray();
	int diff = std::numeric_limits<int>::max();
	std::pair<int, int> diffPair;
	for (size_t i = 1; i < _sortedArr.size(); ++i)
	{
		int currentDiff = _sortedArr[i] - _sortedArr[i - 1];
		if (currentDiff < diff)
		{
			diff = currentDiff;
			diffPair = std::make_pair(_sortedArr[i - 1], _sortedArr[i]);
		}
	}
	std::cout << "is between " << diffPair.second << " - " << diffPair.first << " = ";
	return diff;
}

int Span::longestSpan(void)
{
	if (_count < 2)
		throw SmallSizeException();
	sortArray();
	int min = _sortedArr[0];
	int max = _sortedArr[_sortedArr.size() - 1];
	std::cout << "is between " << max << " - " << min << " = ";
	return max - min;
}

const char *Span::FullArrayException::what() const throw()
{
	return ("Array is full");
}

const char *Span::SmallSizeException::what() const throw()
{
	return ("Array is too small");
}