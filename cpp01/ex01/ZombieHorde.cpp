#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *Zombiehorde = new Zombie[N];
    for (int i = 0; i < N; i++)
      Zombiehorde[i].setName(name);
    return Zombiehorde;
}
