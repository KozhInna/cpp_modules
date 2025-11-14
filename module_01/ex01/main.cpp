/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:41:06 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/14 14:12:22 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>

int main(void)
{
    {
        int N = 3;
        std::cout << std::string(30, '-') << std::endl;
        std::cout << "Horde of 3\n" << std::endl;
        Zombie* horde = zombieHorde(N, "Trr");
        for (int i = 0; i < N; i++)
        {
            if (horde)
                horde[i].announce();
        }
        delete[] horde;
    }
    {
        int N = 0;
        std::cout << std::string(30, '-') << std::endl;
        std::cout << "Horde of 0\n" << std::endl;
        Zombie* horde = zombieHorde(N, "Bzz");
        for (int i = 0; i < N; i++)
        {
            if (horde)
                horde[i].announce();
        }
        delete[] horde;
    }
    {
        int N = -5;
        std::cout << '\n' << std::string(30, '-') << std::endl;
        std::cout << "Horde of -5\n" << std::endl;
        Zombie* horde = zombieHorde(N, "Bzz");
        for (int i = 0; i < N; i++)
        {
            if (horde)
                horde[i].announce();
        }
        delete[] horde;
    }
    // {
    //     int N = 1000;
            // std::cout << '\n' << std::string(30, '-') << std::endl;
    //     std::cout << "Horde of 1000\n" << std::endl;
    //     Zombie* horde = zombieHorde(N, "Bzz");
    //     for (int i = 0; i < N; i++)
    //     {
    //         if (horde)
    //             horde[i].announce();
    //     }
    //     delete[] horde;
    // }
    {
        int N = 5;
        std::cout << '\n' << std::string(30, '-') << std::endl;
        std::cout << "No name\n" << std::endl;
        Zombie* horde = zombieHorde(N, "");
        for (int i = 0; i < N; i++)
        {
            if (horde)
                horde[i].announce();
        }
        delete[] horde;
    }
    return 0;
}