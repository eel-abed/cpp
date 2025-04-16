/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:48:56 by eel-abed          #+#    #+#             */
/*   Updated: 2025/04/16 19:25:57 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5;
	std::string zombieName = "Horde Member";

	std::cout << "Création d'une horde de " << N << " zombies nommés \"" << zombieName << "\"" << std::endl;
	Zombie* horde = zombieHorde(N,zombieName);
	
	for (int i = 0; i < N; i++)
	{
		std::cout << "Zombie " << i << " annonce: ";
		horde[i].announce();
	}

	std::cout << "\nDestruction de la horde..." << std::endl;
	delete[] horde;
	
	return 0;
}
