/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:32:28 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/03 13:24:07 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

//default constructor
ScavTrap::ScavTrap()
{
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
	std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
	std::cout << "ScavTrap parametarised constructor" << std::endl;
}

//copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor" << std::endl;
}

//copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

//destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints_ > 0 && energyPoints_ > 0)
	{
		energyPoints_--;
		std::cout << "ScavTrap " << name_ << " attacks " << target << " causing "
		<< attackDamage_ << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << name_ << " can't attack" << std::endl;
}

void ScavTrap::guardGate()
{
	if (hitPoints_ > 0)
		std::cout << "ScavTrap " << name_ << " is now in Gate keeper mode" << std::endl;
	else
		std::cout << "ScavTrap " << name_ << " can't be in Gate keeper mode" << std::endl;
}
