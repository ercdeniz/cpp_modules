#include <iostream>

int main(int ac, char **av) {
	if (ac != 1) {
		for (int i = 1; i < ac; ++i) {
			for (int j = 0; av[i][j] != '\0'; ++j) {
				char letter = std::toupper(static_cast<unsigned char>(av[i][j]));
				std::cout << letter << std::flush;
			}
			if (i + 1 < ac)
				std::cout << " ";
		}
	}
	else
		std::cout << "I need something for the announcement, man.";
	std::cout << std::endl;
	return 0;
}
