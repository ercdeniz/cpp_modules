#pragma once

#include <iostream>

//COLORS
#define RESET "\033[0m"

enum Color {
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    COLOR_COUNT
};

const char* colorCodes[COLOR_COUNT] = {
    "\033[1;31m",  // RED
    "\033[1;32m",  // GREEN
    "\033[1;33m",  // YELLOW
    "\033[1;34m",  // BLUE
    "\033[1;35m",  // MAGENTA
    "\033[1;36m"   // CYAN
};

template <typename T>
void iter(T *arr, int len, void (*func)(T const &))
{
    for (int i = 0; i < len; i++)
        func(arr[i]);
}

template <typename T>
void print(T const &x)
{
    srand(time(0));
    int random = rand() % COLOR_COUNT;
    std::cout << colorCodes[random] << x << RESET << std::endl;
}

template <typename T>
void sum(T const &x)
{
    static T total = 0; // Static variable to hold the total sum
    total += x;
    print("current total: " + std::to_string(total));
}
