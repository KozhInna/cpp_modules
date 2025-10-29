/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:14:18 by ikozhina          #+#    #+#             */
/*   Updated: 2025/10/29 11:16:07 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    for (int i = 1; i < argc; i++)
    {
        std::string str{argv[i]};
        for (char c : str)
            std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    }
    std::cout << std::endl;
    return (0);
}