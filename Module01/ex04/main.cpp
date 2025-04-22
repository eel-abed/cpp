/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:14:22 by eel-abed          #+#    #+#             */
/*   Updated: 2025/04/22 18:17:40 by eel-abed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <S1> <S2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if(s1.empty())
	{
		std::cerr << "Error: string string to find can't be empty" << std::endl;
		return 1;
	}
	
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "error : can't open file" << filename << std::endl;
		return 1;
	}

	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());

	if (!outputFile.is_open())
	{
		std::cerr << "Error: could not create file " << outputFilename << std::endl;
		inputFile.close();
		return 1;
	}
	
	std::string line;

	while (std::getline(inputFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos +s1.length());
			pos += s2.length();
		}
		outputFile << line;

		if (!inputFile.eof())
		{
			outputFile << std::endl;
		}
		
	}

	inputFile.close();
	outputFile.close();

	std::cout << "Replacment completed New file created : " << outputFilename << std::endl;
	return 0;
	
}
