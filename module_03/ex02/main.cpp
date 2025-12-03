/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:02:30 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/03 13:08:35 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== ClapTrap objects ===" << std::endl;
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
	std::cout << "\n=== ScavTrap objects ===" << std::endl;
	{
		ScavTrap c1;
		ScavTrap c2("Tim");
		c1 = c2;
	}
	std::cout << std::endl;
	{
		ScavTrap c3("Tim");
		ScavTrap c4 = c3;
	}
	std::cout << std::endl;
	{
		ScavTrap z1("Bob");
		std::cout << "ScavTrap has " << z1.getEnergyPoints() << " energy points" << std::endl;
		for(int i = z1.getEnergyPoints(); i > 0; i--)
		{
			z1.attack("Nick");
		}
		z1.attack("Nick");
		z1.beRepaired(1);
	}
	std::cout << std::endl;
	{
		ScavTrap z1("Bob");
		z1.guardGate();
	}
	std::cout << std::endl;
	{
		ScavTrap z2("Billy");

		std::cout << "ScavTrap has " << z2.getHitPoints() << " hit points" << std::endl;
		z2.beRepaired(1);
		std::cout << "ScavTrap has " << z2.getHitPoints() << " hit points" << std::endl;

		z2.takeDamage(100);
		z2.takeDamage(5);
		z2.attack("Nick");
		z2.beRepaired(1);
	}
	std::cout << "\n=== FragTrap objects ===" << std::endl;
	{
		FragTrap c1;
		FragTrap c2("Tim");
		c1 = c2;
	}
	std::cout << std::endl;
	{
		FragTrap c3("Tim");
		FragTrap c4 = c3;
	}
	std::cout << std::endl;
	{
		FragTrap z1("Bob");
		std::cout << "FragTrap has " << z1.getEnergyPoints() << " energy points" << std::endl;
		for(int i = z1.getEnergyPoints(); i > 0; i--)
		{
			z1.attack("Nick");
		}
		z1.attack("Nick");
		z1.beRepaired(1);
	}
	std::cout << std::endl;
	{
		FragTrap z1("Bob");
		z1.highFivesGuys();
	}
	std::cout << std::endl;
	{
		FragTrap z2("Billy");

		std::cout << "FragTrap has " << z2.getHitPoints() << " hit points" << std::endl;
		z2.beRepaired(1);
		std::cout << "FragTrap has " << z2.getHitPoints() << " hit points" << std::endl;

		z2.takeDamage(100);
		z2.takeDamage(5);
		z2.attack("Nick");
		z2.beRepaired(1);
	}
	return 0;
}