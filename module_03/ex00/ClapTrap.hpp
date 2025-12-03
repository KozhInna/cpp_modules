/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:26:04 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/03 10:10:36 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ClapTrap
{
	private:
		std::string name_;
		int hitPoints_;
		int energyPoints_;
		int attackDamage_;

	public:
		ClapTrap(); //default constructor
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other); //copy constructor
		ClapTrap& operator=(const ClapTrap& other); //copy assignment operator
		~ClapTrap(); //destructor

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		int getHitPoints() const;
		int getEnergyPoints() const;
};