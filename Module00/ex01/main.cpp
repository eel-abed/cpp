/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:47:12 by eel-abed          #+#    #+#             */
/*   Updated: 2025/04/08 17:59:08 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string command;
	
	std::cout << "------Welcome to PhoneBook------" << std::endl;
	std::cout << "AVAILABLE COMMANDS : ADD, SEARCH, EXIT" << std::endl;

	while (true)
	{
		std::cout << "\n>> ";
		std::getline(std::cin, command);

		if (std::cin.eof())
		{
			std::cout << "\n EXITING... Bye-Bye" << std::endl;
			break;
		}
		
		if (command == "ADD")
		{
			phoneBook.addContact();
		}
		else if (command == "SEARCH")
		{
			phoneBook.searchContact();
		}
		else if (command == "EXIT")
		{
			std::cout << "Salam" << std::endl;
			break;
		}
		else {
			std::cout << "INVALID COMMAND. AVAILABLE COMMAND : ADD, SEARCH, EXIT" << std::endl;
		}
		
	}
	return 0;
}
