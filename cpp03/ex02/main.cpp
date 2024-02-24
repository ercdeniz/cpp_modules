#include "FragTrap.hpp"

FragTrap *Frag = new FragTrap("Frag");
FragTrap *trap = new FragTrap("trap");
FragTrap *hiFiveGhost = new FragTrap("hiFiveGhost");

void setPoints()
{
    if(Frag->getHitPoints() < trap->getHitPoints())
		hiFiveGhost->setHitPoints(Frag->getHitPoints());
    else
        hiFiveGhost->setHitPoints(trap->getHitPoints());
	if(Frag->getEnergyPoints() < trap->getEnergyPoints())
		hiFiveGhost->setEnergyPoints(Frag->getEnergyPoints());
	else
		hiFiveGhost->setEnergyPoints(trap->getEnergyPoints());
}

int main(void)
{
    int FragAmount;
    int trapAmount;

    while (true)
    {
        std::cout << CYAN << "Enter a damage amount(int): " << RESET;
        std::cin >> FragAmount;
        if (std::cin.fail() || std::cin.peek() != '\n' || FragAmount < 0)
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
        Frag->setAttackDamage(FragAmount);
        trap->setAttackDamage(trapAmount);
        trap->attack("Frag");
        Frag->attack("trap");
        Frag->takeDamage(trapAmount);
        trap->takeDamage(FragAmount);
        Frag->beRepaired(trapAmount / 2 + trapAmount % 2);
        trap->beRepaired(FragAmount / 2 + FragAmount % 2);
        std::cout << PURPLE << "Frag's energy: " << Frag->getEnergyPoints()
            << std::endl << "trap's energy: " << trap->getEnergyPoints() << RESET << std::endl;
        std::cout << PURPLE << "Frag's hit points: " << Frag->getHitPoints()
            << std::endl << "trap's hit points: " << trap->getHitPoints() << RESET << std::endl;
		setPoints();
        if (Frag->getEnergyPoints() == 0 || trap->getEnergyPoints() == 0)
        {
            std::cout << BOLD RED << Frag->getName() << " or " << trap->getName() << " no energy" << RESET << std::endl;
            break;
        }
        if (Frag->getHitPoints() == 0 || trap->getHitPoints() == 0)
        {
            std::cout << BOLD RED << Frag->getName() << " or " << trap->getName() << " is destroyed!" << RESET << std::endl;
            break;
        }
        hiFiveGhost->highFivesGuys();
    }
    hiFiveGhost->highFivesGuys();
    delete Frag;
    delete trap;
    delete hiFiveGhost;
    return (0);
}