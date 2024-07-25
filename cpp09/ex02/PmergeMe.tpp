#pragma once

template <typename T>
T fordJhonson(T &left, T &right)
{
	T result;
	typename T::iterator itLeft = left.begin();
	typename T::iterator itRight = right.begin();

	while (itLeft != left.end() && itRight != right.end())
	{
		if (*itLeft < *itRight)
		{
			result.push_back(*itLeft);
			++itLeft;
		}
		else
		{
			result.push_back(*itRight);
			++itRight;
		}
	}

	while (itLeft != left.end())
	{
		result.push_back(*itLeft);
		++itLeft;
	}

	while (itRight != right.end())
	{
		result.push_back(*itRight);
		++itRight;
	}

	return result;
}

template <typename T>
void PmergeMe::mergeSort(T &arr)
{
	if (arr.size() <= 1)
		return;

	T left(arr.begin(), arr.begin() + arr.size() / 2);
	T right(arr.begin() + arr.size() / 2, arr.end());

	mergeSort(left);
	mergeSort(right);

	arr = fordJhonson(left, right);
}