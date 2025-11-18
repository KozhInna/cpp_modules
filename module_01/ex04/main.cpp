/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:55:26 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/18 19:40:43 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

bool checkArgv(int argc, char** argv);
void readFile(char* argv, char* s1, char* s2);
int readReplaceWrite(char* fileName, std::string line, char* s1, char* s2);

int main(int argc, char** argv)
{
    if (!checkArgv(argc, argv))
        return (0);
    
    readFile(argv[1], argv[2], argv[3]);
}

bool checkArgv(int argc, char** argv)
{
    if (argc != 4)
        return false;
    return true;   
}

void readFile(char* fileName, char* s1, char* s2)
{
    std::ifstream ifs(fileName);
    std::string line{};
    if (ifs.is_open())
    {
        while (!ifs.eof())
        {
            getline(ifs, line);
            readReplaceWrite(fileName, line, s1, s2);
        }
        ifs.close();
    }
    else
    {
        std::cout << "can't open file" << std::endl;
    }
}

int readReplaceWrite(char* fileName, std::string line, char* s1, char* s2)
{
    std::string newstr{}, str1{s1}, str2{s2};
    size_t res = -1;
    int i = 0;
    while ((res = line.find(str1, res + 1)) != std::string::npos) //not found position
    {
        // std::cout << res << " ";
        newstr.append(line.begin() + i, line.begin() + res); 
        newstr.append(str2); 
        i = res + str1.length();
    }
    newstr.append(line.begin() + i, line.end());
    std::string file = fileName;
    std::string outFile = file + ".replace";
    std::ofstream ofs(outFile, std::ios::app);
    if (ofs.is_open())
    {
        ofs << newstr << "\n";
    }
    ofs.close();
    // std::cout << "\n" << newstr << std::endl;      
    return 0; 
}


/* It will open the file <filename> and copies its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2. */