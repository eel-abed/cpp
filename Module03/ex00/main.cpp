#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("R2D2");
	clap.attack("enemy robot");
	clap.attack("another target");

	clap.takeDamage(5);

	clap.beRepaired(2);

	ClapTrap tired("GROS_BOT");
	for (int i = 0; i < 10; i++)
	{
		tired.attack("dummy");
	}
	tired.attack("should,T not work");

	ClapTrap weak("NPC");
	weak.takeDamage(20);
	weak.attack("ghost");

	return 0;
}
