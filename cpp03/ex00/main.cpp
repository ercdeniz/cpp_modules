#include "ClapTrap.hpp"
#include <limits>

int main() {
	ClapTrap *clap = new ClapTrap("clap");
	ClapTrap *trap = new ClapTrap("trap");
	int clapAmount;
	int trapAmount;

	while (true) {
		std::cout << CYAN << "Enter a damage amount(int): " << RESET;
		std::cin >> clapAmount;
		if (std::cin.fail() || std::cin.peek() != '\n' || clapAmount < 0){
			std::cout << RED << "Invalid input. Exiting." << RESET << std::endl;
			break;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << CYAN << "Enter a damage amount(int): " << RESET;
		std::cin >> trapAmount;
		if (std::cin.fail() || std::cin.peek() != '\n' || trapAmount < 0){
			std::cout << RED << "Invalid input. Exiting." << RESET << std::endl;
			break;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		clap->setAttackDamage(clapAmount);
		trap->setAttackDamage(trapAmount);

		clap->attack("trap");
		trap->attack("clap");
		clap->takeDamage(trapAmount);
		trap->takeDamage(clapAmount);
		clap->beRepaired(trapAmount / 2 + trapAmount % 2);
		trap->beRepaired(clapAmount / 2 + clapAmount % 2);
		std::cout <<PURPLE << "clap's energy: " << clap->getEnergyPoints()
			<< std::endl << "trap's energy: " << trap->getEnergyPoints() << RESET << std::endl;
		std::cout <<PURPLE << "clap's hit points: " << clap->getHitPoints()
			<< std::endl << "trap's hit points: " << trap->getHitPoints() << RESET << std::endl;
		if (clap->getEnergyPoints() == 0 || trap->getEnergyPoints() == 0 ){
			std::cout << BOLD RED << clap->getName() << " or " << trap->getName() << " no energy" << RESET << std::endl;
			break;
		}
		if(clap->getHitPoints() == 0 || trap->getHitPoints() == 0){
			std::cout << BOLD RED << clap->getName() << " or " << trap->getName() << " is destroyed!" << RESET << std::endl;
			break;
		}
	}
	delete clap;
	delete trap;
	return 0;
}
