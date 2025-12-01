/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:02:30 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/01 14:06:42 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    {    
        ClapTrap c1;
        ClapTrap c2("Tim");
        c1 = c2;

        ClapTrap c3("Tim");
        ClapTrap c4 = c3;
    }
    {    
        ClapTrap z1("Bob");
        
        for(int i = z1.getEnergyPoints(); i > 0; i--)
        {
            z1.attack("Nick");
        }
        z1.attack("Nick");
        z1.beRepaired(1);
    }
    {
        ClapTrap z2("Billy");
        
        z2.beRepaired(1);
        
        for(int i = z2.getHitPoints(); i > 0; i--)
        {
            z2.takeDamage(1);
        }
        z2.attack("Nick");
        z2.beRepaired(1);
    }
}