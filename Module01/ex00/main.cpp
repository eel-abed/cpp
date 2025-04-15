/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:12:47 by eel-abed          #+#    #+#             */
/*   Updated: 2025/04/15 19:17:07 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "Creating a heap Zombie name Gaétan" << std::endl;
	Zombie* heapZombie = newZombie("Gaétan");
	heapZombie->announce();

	std::cout << "\nCreating a stack zombie named Mahmoud" << std::endl;
	randomChump("Mahmoud");

	std::cout << "\nDestroying heap zombie" << std::endl;
	delete heapZombie;	
}
