#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " cannot attack because it has no hit points left!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " cannot attack because it has no energy points left!" << std::endl;
		return;
	}

	_energyPoints--;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " wants a highfive now!" << std::endl;
}
