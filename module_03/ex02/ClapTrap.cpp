/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:07:05 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/03 13:18:22 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

//default constructor
ClapTrap::ClapTrap()
	: name_("unnamed"), hitPoints_(10), energyPoints_(10), attackDamage_(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0)
{
	std::cout << "ClapTrap parametarised constructor called" << std::endl;
}

//copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
	: name_(other.name_), hitPoints_(other.hitPoints_),
	energyPoints_(other.energyPoints_), attackDamage_(other.attackDamage_)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

//copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
	}
	return *this;
}

//destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints_ > 0 && energyPoints_ > 0)
	{
		energyPoints_--;
		std::cout << "ClapTrap " << name_ << " attacks " << target << " causing "
		<< attackDamage_ << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name_ << " can't attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints_ <= 0)
	{
		std::cout << "ClapTrap " << name_ << " is already dead!" << std::endl;
		return ;
	}
	if (hitPoints_ <= static_cast<int>(amount))
	{
		std::cout << "ClapTrap " << name_ << " takes " << amount
		<< " points of damage and dies!" << std::endl;
		hitPoints_ = 0;
	}
	else
	{
		hitPoints_ -= amount;
		std::cout << "ClapTrap " << name_ << " takes " << amount
		<< " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints_ > 0 && energyPoints_ > 0)
	{
		hitPoints_ += amount;
		energyPoints_--;
		std::cout << "ClapTrap " << name_ << " is being repaired" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name_ <<  " can't be repaired" << std::endl;
}

int ClapTrap::getHitPoints() const
{
	return hitPoints_;
}

int ClapTrap::getEnergyPoints() const
{
	return energyPoints_;
}