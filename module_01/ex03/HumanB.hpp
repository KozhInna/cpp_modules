/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:52:33 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/16 21:34:58 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <string>

class HumanB
{
    private: 
        std::string name_;
        Weapon* weapon;
    
    public:
        HumanB(const std::string& n);
        ~HumanB();
        void attack() const;
        void setWeapon(Weapon& w);
};