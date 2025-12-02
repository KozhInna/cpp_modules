/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:57:32 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/02 10:20:13 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

//default constructor
ClapTrap::ClapTrap() {
    std::cout << "ClapTrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name_(name) {
    std::cout << "ClapTrap parametarised constructor" << std::endl;
}
 
//copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) 
    : name_(other.name_), hitPoints_(other.hitPoints_), 
    energyPoints_(other.energyPoints_), attackDamage_(other.attackDamage_) {
    std::cout << "ClapTrap copy constructor" << std::endl;
}

//copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap copy assignment operator" << std::endl;
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
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (!hitPoints_ || !energyPoints_)
    {
        std::cout << "ClapTrap  " << name_ << " can't attack" << std::endl;
        return ;
    }
    energyPoints_--;        
    std::cout << "ClapTrap " << name_ << " attacks " << target << " causing " 
    << attackDamage_ << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    hitPoints_ -= amount;
    std::cout << "ClapTrap " << name_ << " takes " << amount 
    << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints_ && energyPoints_)
    {
        hitPoints_ += amount;
        energyPoints_--;       
    }
    std::cout << "ClapTrap " << name_
        << ((hitPoints_ && energyPoints_) ? " is being repaired" : " can't be repaired")
        << std::endl;
}

int ClapTrap::getHitPoints() const {
    return hitPoints_;
}

int ClapTrap::getEnergyPoints() const {
    return energyPoints_;
}