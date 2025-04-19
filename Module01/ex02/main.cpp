/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:48:56 by eel-abed          #+#    #+#             */
/*   Updated: 2025/04/19 16:07:16 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{

	std::string string = "HI THIS IS BRAIN";

	std::string *stringPTR = &string;

	std::string &stringREF = string;

	std::cout << "Memory addresses:" << std::endl;
	std::cout << "Address of string: " << &string << std::endl;
	std::cout << "Address stringPTR: " << stringPTR << std::endl;
	std::cout << "Address stringREF: " << &stringREF << std::endl;
	std::cout << "\nValues:" << std::endl;
	std::cout << "Value of string: " << string << std::endl;
	std::cout << "Value stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value stringREF: " << stringREF << std::endl;

	return 0;
}
