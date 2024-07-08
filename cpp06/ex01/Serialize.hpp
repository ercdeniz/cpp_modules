#pragma once

#include <iostream>
#include <cstdint>

// Colors
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

typedef struct Data
{
	int i;
} Data;

class Serialize
{
	private:
		Serialize();
		Serialize(const Serialize &other);
		Serialize &operator=(const Serialize &other);
		~Serialize();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

