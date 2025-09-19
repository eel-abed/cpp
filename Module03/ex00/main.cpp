#include "ClapTrap.hpp"

int main()
{
	// Creating a ClapTrap
	ClapTrap clap("R2D2");

	// Testing attack
	clap.attack("enemy robot");
	clap.attack("another target");

	// Testing taking damage
	clap.takeDamage(5);
	clap.takeDamage(3);

	// Testing repair
	clap.beRepaired(2);

	// Testing what happens when no energy
	ClapTrap tired("GROS_BOT");
	for (int i = 0; i < 10; i++)
	{
		tired.attack("dummy");
	}
	tired.attack("should not work");

	// Testing what happens when destroyed
	ClapTrap weak("NPC");
	weak.takeDamage(20);
	weak.attack("ghost");

	return 0;
}
