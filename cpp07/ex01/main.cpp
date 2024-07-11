#include "iter.hpp"

int main()
{
    int int_arr[] = {1, 2, 3, 4, 5};
    iter(int_arr, 5, sum);
    print("-------");
    std::string str_arr[5] = {"one", "two", "three", "four", "five"};
    iter(str_arr, 5, print);
    return 0;
}