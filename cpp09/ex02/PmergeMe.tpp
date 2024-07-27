#pragma once

template <typename Iterator>
void insertionSort(Iterator begin, Iterator end)
{
    for (Iterator i = begin + 1; i != end; ++i)
    {
        typename std::iterator_traits<Iterator>::value_type key = *i;
        Iterator j = i - 1;
        while (j >= begin && *j > key)
        {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = key;
    }
}

template <typename Iterator>
void merge(Iterator begin, Iterator mid, Iterator end)
{
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    std::vector<value_type> temp(distance(begin, end));
    Iterator left = begin;
    Iterator right = mid;
    typename std::vector<value_type>::iterator it = temp.begin();

    while (left != mid && right != end)
    {
        if (*left <= *right)
        {
            *it = *left;
            ++left;
        }
        else
        {
            *it = *right;
            ++right;
        }
        ++it;
    }

    it = copy(left, mid, it);
    it = copy(right, end, it);
    copy(temp.begin(), temp.end(), begin);
}

template <typename Iterator>
void PmergeMe::fordJohnsonSort(Iterator begin, Iterator end)
{
    typename std::iterator_traits<Iterator>::difference_type dist = distance(begin, end);
    if (dist > 1)
    {
        if (dist <= 16)
            insertionSort(begin, end);
        else
        {
            Iterator mid = begin + dist / 2;
            fordJohnsonSort(begin, mid);
            fordJohnsonSort(mid, end);
            merge(begin, mid, end);
        }
    }
}