/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:09:47 by eel-abed          #+#    #+#             */
/*   Updated: 2025/04/19 18:57:40 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type)
{
}

const std::string& Weapon::getType() const
{
	return this->type;
}

void Weapon::setType(const std::string& type)
{
	this->type = type;
}
