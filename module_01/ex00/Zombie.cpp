/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:33:16 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/21 09:33:31 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie() {}

Zombie::Zombie(std::string zombieName): name(zombieName)
{
	std::cout << name << "\033[32m" << " is created" << "\033[0m" << std::endl;
}
Zombie::~Zombie()
{
	std::cout << name << "\033[31m" << " is destroyed" << "\033[0m" << std::endl;
}


void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
