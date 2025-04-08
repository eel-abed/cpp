/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:47:54 by eel-abed          #+#    #+#             */
/*   Updated: 2025/04/08 18:07:19 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	oldestContactIndex = 0;
	contactCount = 0;
}

void PhoneBook::addContact()
{

	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

	std::cout << "ENTER FIRST NAME : ";
	std::getline(std::cin, firstName);
	if (std::cin.eof())
		return;

	std::cout << "ENTER LAST NAME : ";
	std::getline(std::cin, lastName);
	if (std::cin.eof())
		return;

	std::cout << "ENTER NICKNAME : ";
	std::getline(std::cin, nickName);
	if (std::cin.eof())
		return;

	std::cout << "ENTER PHONE NUMBER : ";
	std::getline(std::cin, phoneNumber);
	if (std::cin.eof())
		return;

	std::cout << "ENTER DARKEST SECRET : ";
	std::getline(std::cin, darkestSecret);
	if (std::cin.eof())
		return;

	if (firstName.empty() || lastName.empty() || nickName.empty() || phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "ALL THE FIELDS MUST BE FILLED !!!!!!!!!!!!! CONTACT NOT ADDED MAN L" << std::endl;
		return;
	}

	contacts[oldestContactIndex].setFirstName(firstName);
	contacts[oldestContactIndex].setLastName(lastName);
	contacts[oldestContactIndex].setNickName(nickName);
	contacts[oldestContactIndex].setPhoneNumber(phoneNumber);
	contacts[oldestContactIndex].setDarkestSecret(darkestSecret);

	if (contactCount < 8)
	{
		contactCount++;
	}

	// Quand on arrive a 8, revient a 0
	oldestContactIndex = (oldestContactIndex + 1) % 8;

	std::cout << "-- CONTACT ADDED SUCCESSFULLY :) --" << std::endl;
}

// recherche contact annuaire
void PhoneBook::searchContact()
{
	if (contactCount == 0)
	{
		std::cout << "PHONEBOOK IS EMPTY." << std::endl;
		return;
	}

	displayContactList();

	std::string input;
	int index;

	std::cout << "INDEX of the contact to display : ";
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		return;
	}

	// Utilisons std::stringstream au lieu de std::stoi)
	std::stringstream ss(input);
	
	// On essaie de convertir l'entrée en entier
	if (ss >> index && ss.eof())
	{
		if (index >= 0 && index < contactCount)
		{
			displayContactDetails(index);
		}
		else
		{
			std::cout << "INVALIDE INDEX!!" << std::endl;
		}
	}
	else
	{
		std::cout << "INVALID INPUT! PLEASE ENTER A NUMBER." << std::endl;
	}
}

void PhoneBook::displayContactList() const
{
	std::cout << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRST NAME" << "|";
	std::cout << std::setw(10) << "LAST NAME" << "|";
	std::cout << std::setw(10) << "NICKNAME" << "|";
	std::cout << std::string(43, '=') << std::endl;

	for (int i = 0; i < contactCount; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncateString(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncateString(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncateString(contacts[i].getNickName()) << std::endl;
	}
}

void PhoneBook::displayContactDetails(int index) const
{
	std::cout << "\nContact Details:" << std::endl;
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

std::string PhoneBook::truncateString(const std::string &str) const
{
	if (str.length() > 10)
	{
		return str.substr(0,9) + ".";
	}
	return str;
}
