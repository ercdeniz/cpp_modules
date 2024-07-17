#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <limits>

// Colors
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

#define MAXRAND 1000

class Span
{
	private:
		unsigned int _N;
		unsigned int _count;
		std::vector<int> _arr;
		std::vector<int> _sortedArr;
		Span(void);

	public:
		Span(unsigned int N);
		Span(const Span &copy);
		~Span(void);
		Span &operator=(const Span &other);

		const std::vector<int> &getArr(void) const;

		int getRandomNumber(void) const;
		void addNumber(const int number);
		void sortArray();
		int shortestSpan(void);
		int longestSpan(void);

		class FullArrayException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class SmallSizeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};