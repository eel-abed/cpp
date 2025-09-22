#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	// Testing ClapTrap
	ClapTrap clap("CL4P");
	clap.attack("bandit");
	clap.takeDamage(5);
	clap.beRepaired(3);

	// Testing ScavTrap
	ScavTrap scav("SC4V");
	scav.attack("psycho");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();

	// Testing energy depletion
	ScavTrap bot("BOT");
	for (int i = 0; i < 51; i++) {
		bot.attack("dummy");
	}

	return 0;
}
