/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:21:39 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/21 09:34:25 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(const std::string& n, Weapon& w): name_(n), weapon(w) {}

HumanA::~HumanA() {}

void HumanA::attack() const
{
	std::cout << name_ << " attacks with their " << weapon.getType() << std::endl;
}
