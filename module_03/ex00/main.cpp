/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:02:30 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/03 13:08:51 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	{
		ClapTrap c1;
		ClapTrap c2("Tim");
		c1 = c2;
	}
	std::cout << std::endl;
	{
		ClapTrap c3("Tim");
		ClapTrap c4 = c3;
	}
	std::cout << std::endl;
	{
		ClapTrap z1("Bob");

		std::cout << "ClapTrap has " << z1.getEnergyPoints() << " energy points" << std::endl;
		for(int i = z1.getEnergyPoints(); i > 0; i--)
		{
			z1.attack("Nick");
		}
		z1.attack("Nick");
		z1.beRepaired(1);
	}
	std::cout << std::endl;
	{
		ClapTrap z2("Billy");

		std::cout << "ClapTrap has " << z2.getHitPoints() << " hit points" << std::endl;
		z2.beRepaired(1);
		std::cout << "ClapTrap has " << z2.getHitPoints() << " hit points" << std::endl;
		z2.takeDamage(100);
		z2.takeDamage(5);
		z2.attack("Nick");
		z2.beRepaired(1);
	}
	return 0;
}