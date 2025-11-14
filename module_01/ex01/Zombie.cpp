/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:41:09 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/14 13:46:09 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>

Zombie::Zombie() : name("Unnamed") 
{
    std::cout << name  << "\033[32m" << " is created" << "\033[0m" << std::endl;
};

Zombie::Zombie(std::string zombieName) : name(zombieName)
{
    std::cout << name << "\033[32m" << " is created" << "\033[0m" << std::endl;
}

Zombie::Zombie(const Zombie& other) : name(other.name) {}

Zombie& Zombie::operator=(const Zombie& other)
{
    if (this != &other)
        name = other.name;
    return *this;
}

Zombie::~Zombie()
{
	std::cout << name << "\033[31m" << " is destroyed" << "\033[0m" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string zombieName)
{
    name = zombieName;
}
