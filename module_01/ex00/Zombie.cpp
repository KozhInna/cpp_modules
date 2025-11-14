/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:33:16 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/14 23:14:53 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

// Default Constructor
Zombie::Zombie() {}

// Copy Constructor
Zombie::Zombie(const Zombie& other) : name(other.name) {}

// Copy Assignment Operator
Zombie& Zombie::operator=(const Zombie& other)
{
	if (this != &other)
		name = other.name;
	return *this;
}

// Destructor
Zombie::~Zombie()
{
	std::cout << name << "\033[31m" << " is destroyed" << "\033[0m" << std::endl;
}

// Parameterized Constructor
Zombie::Zombie(std::string zombieName): name(zombieName)
{
	std::cout << name << "\033[32m" << " is created" << "\033[0m" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
