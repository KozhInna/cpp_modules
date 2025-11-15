/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:41:09 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/15 10:37:29 by ikozhina         ###   ########.fr       */
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
