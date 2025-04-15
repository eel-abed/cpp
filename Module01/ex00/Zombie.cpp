/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:49:09 by eel-abed          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:39 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
}

Zombie::~Zombie()
{
	std::cout << name << " Has been destroeyed " << std::endl;
}

void Zombie::announce (void) 
{
	std::cout << name << ": BRAINZ... ou jsp la" << std::endl;
}
