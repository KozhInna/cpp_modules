/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:41:09 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/14 23:48:32 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() 
{
    static int count = 0;
    count++;
    std::cout  << "Zombie " << count << " is created" << std::endl;
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
    std::cout << name << " is destroyed" << "\033[0m" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string zombieName)
{
    name = zombieName;
}
