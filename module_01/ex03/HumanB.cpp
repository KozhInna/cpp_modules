/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:52:35 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/21 09:34:36 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(const std::string& n): name_(n), weapon(nullptr) {}

HumanB::~HumanB() {}

void HumanB::attack() const
{
	if (weapon)
		std::cout << name_ << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name_ << " has no weapon " << std::endl;
}

void HumanB::setWeapon(Weapon& w)
{
	weapon = &w;
}