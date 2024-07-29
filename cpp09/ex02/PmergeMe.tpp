#pragma once

template <typename Iterator>
void insertionSort(Iterator begin, Iterator end)
{
	if (begin == end)
		return;

	for (Iterator i = begin + 1; i != end; ++i)
	{
		typename std::iterator_traits<Iterator>::value_type value = *i;
		Iterator j = i;
		while (j != begin && *(j - 1) > value)
		{
			*j = *(j - 1);
			--j;
		}
		*j = value;
	}
}

template <typename Iterator>
void merge(Iterator begin, Iterator mid, Iterator end)
{
	typedef typename std::iterator_traits<Iterator>::value_type type;
	std::vector<type> temp(std::distance(begin, end));
	Iterator left = begin;
	Iterator right = mid;
	typename std::vector<type>::iterator it = temp.begin();
	while (left != mid && right != end)
	{
		if (*left <= *right)
			*it++ = *left++;
		else
			*it++ = *right++;
	}
	std::copy(left, mid, it);
	std::copy(right, end, it);
	std::copy(temp.begin(), temp.end(), begin);
}

template <typename Iterator>
void PmergeMe::fordJohnsonSort(Iterator begin, Iterator end)
{
	typename std::iterator_traits<Iterator>::difference_type dist = std::distance(begin, end);
	if (dist > 1)
	{
		if (dist <= 16)
			insertionSort(begin, end);
		else
		{
			Iterator mid = begin;
			std::advance(mid, dist / 2);
			fordJohnsonSort(begin, mid);
			fordJohnsonSort(mid, end);
			merge(begin, mid, end);
		}
	}
}
