#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap frag("FR4G");
	
	frag.attack("mutant");
	frag.takeDamage(50);
	frag.beRepaired(20);
	frag.highFivesGuys();
	
	FragTrap bot("BOT");
	for (int i = 0; i < 5; i++) {
		bot.attack("dummy");
	}
	
	return 0;
}
