/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:38:29 by eel-abed          #+#    #+#             */
/*   Updated: 2025/04/26 17:37:03 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout << "Testing all complaint levels:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::cout << "1. Testing DEBUG level:" << std::endl;
	harl.complain("DEBUG");

	std::cout << "2. Testing INFO level:" << std::endl;
	harl.complain("INFO");

	std::cout << "3. Testing WARNING level:" << std::endl;
	harl.complain("WARNING");

	std::cout << "4. Testing ERROR level:" << std::endl;
	harl.complain("ERROR");

	std::cout << "5. Testing invalid level:" << std::endl;
	harl.complain("INVALID");

	return 0;
}
