/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:12:51 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/03 13:24:19 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
{
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
	std::cout << "FragTrap default constructor" << std::endl;
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
	std::cout << "FragTrap parametarised constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (hitPoints_ > 0)
		std::cout << "FragTrap " << name_ << " requests ✋" << std::endl;
	else
		std::cout << "FragTrap " << name_ << " can't requests ✋" << std::endl;
}