/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:37:17 by eel-abed          #+#    #+#             */
/*   Updated: 2025/04/01 16:13:03 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string arg = argv[i];
			for (size_t j = 0; j < arg.length(); j++)
			{
				std::cout << (char)std::toupper(arg[j]);
			}
			if (i < argc - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
