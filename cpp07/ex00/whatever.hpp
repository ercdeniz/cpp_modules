#pragma once

# include <iostream>

template <typename T>
void swap(T& var1, T& var2)
{
	T temp = var1;
	var1 = var2;
	var2 = temp;
}

template <typename T>
const T& min(const T& var1, const T& var2)
{
	return ((var1 < var2) ? var1 : var2);
}

template <typename T>
const T& max(const T& var1, const T& var2)
{
	return ((var1 > var2) ? var1 : var2);
}
