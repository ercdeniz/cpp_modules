#include "ScavTrap.hpp"

ScavTrap *scav = new ScavTrap("Scav");
ScavTrap *trap = new ScavTrap("trap");
ScavTrap *stupidGuard = new ScavTrap("stupidGuard");

void setPoints()
{
    if(scav->getHitPoints() < trap->getHitPoints())
		stupidGuard->setHitPoints(scav->getHitPoints());
    else
        stupidGuard->setHitPoints(trap->getHitPoints());
	if(scav->getEnergyPoints() < trap->getEnergyPoints())
		stupidGuard->setEnergyPoints(scav->getEnergyPoints());
	else
		stupidGuard->setEnergyPoints(trap->getEnergyPoints());
}

int main(void)
{
    int scavAmount;
    int trapAmount;

    while (true)
    {
        std::cout << CYAN << "Enter a damage amount(int): " << RESET;
        std::cin >> scavAmount;
        if (std::cin.fail() || std::cin.peek() != '\n' || scavAmount < 0)
        {
            std::cout << RED << "Invalid input. Exiting." << RESET << std::endl;
            break;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << CYAN << "Enter a damage amount(int): " << RESET;
        std::cin >> trapAmount;
        if (std::cin.fail() || std::cin.peek() != '\n' || trapAmount < 0)
        {
            std::cout << RED << "Invalid input. Exiting." << RESET << std::endl;
            break;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        scav->setAttackDamage(scavAmount);
        trap->setAttackDamage(trapAmount);

        scav->attack("trap");
        trap->attack("scav");
        scav->takeDamage(trapAmount);
        trap->takeDamage(scavAmount);
        scav->beRepaired(trapAmount / 2 + trapAmount % 2);
        trap->beRepaired(scavAmount / 2 + scavAmount % 2);
        std::cout << PURPLE << "scav's energy: " << scav->getEnergyPoints()
            << std::endl << "trap's energy: " << trap->getEnergyPoints() << RESET << std::endl;
        std::cout << PURPLE << "scav's hit points: " << scav->getHitPoints()
            << std::endl << "trap's hit points: " << trap->getHitPoints() << RESET << std::endl;
        if (scav->getEnergyPoints() == 0 || trap->getEnergyPoints() == 0)
        {
            std::cout << BOLD RED << scav->getName() << " or " << trap->getName() << " no energy" << RESET << std::endl;
			setPoints();
            break;
        }
        if (scav->getHitPoints() == 0 || trap->getHitPoints() == 0)
        {
            std::cout << BOLD RED << scav->getName() << " or " << trap->getName() << " is destroyed!" << RESET << std::endl;
			setPoints();
            break;
        }
  		stupidGuard->guardGate();
    }
    stupidGuard->guardGate();
    delete scav;
    delete trap;
    delete stupidGuard;
    return (0);
}