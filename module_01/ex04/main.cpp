/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:55:26 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/20 20:05:52 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

bool checkArgv(int argc, char** argv);
bool readAndWrite(const std::string& filename, const std::string& s1, const std::string& s2);
std::string replaceInLine(const std::string& line, const std::string& s1, const std::string& s2);

int main(int argc, char** argv)
{
	if (!checkArgv(argc, argv))
		return 1;
	std::string filname{argv[1]}, s1{argv[2]}, s2{argv[3]};
	if (!readAndWrite(filname, s1, s2))
		return 1;
	return 0;
}

bool checkArgv(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: number of arguments" << std::endl;
		std::cerr << "Usage: ./replace <filename> \"s1\" \"s2\"" << std::endl;
		return false;
	}
	std::string strToFind(argv[2]);
	if (strToFind.empty())
	{
		std::cerr << "Error: s1 is empty" << std::endl;
		std::cerr << "Usage: ./replace <filename> \"s1\" \"s2\"" << std::endl;
		return false;
	}
	return true;
}

bool readAndWrite(const std::string& fileName, const std::string& s1, const std::string& s2)
{
	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		std::cerr << "Error: can't open file " << fileName << " for reading" << std::endl;
		return false;
	}
	std::string fileContent{};
	std::getline(ifs, fileContent, '\0');
	ifs.close();
	std::ofstream ofs(fileName + ".replace");
	if (!ofs.is_open())
	{
		std::cerr << "Error: can't create output file " << fileName << ".replace" << std::endl;
		return false;
	}
	ofs << replaceInLine(fileContent, s1, s2);
	if (ofs.fail())
	{
		std::cerr << "Error: failed to write to output file" << std::endl;
		return false;
	}
	ofs.close();
	return true;
}

std::string replaceInLine(const std::string& str, const std::string& s1, const std::string& s2)
{
	std::string newstr{};
	size_t pos = 0;
	size_t i = 0;
	while ((pos = str.find(s1, pos)) != std::string::npos)
	{
		newstr += str.substr(i, pos - i) + s2;
		i = pos + s1.length();
		pos = i;
	}
	newstr += str.substr(i);
	return newstr;
}
