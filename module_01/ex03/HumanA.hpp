/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:32:25 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/21 09:34:30 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <string>

class HumanA
{
	private:
		std::string name_;
		Weapon& weapon;

	public:
		HumanA(const std::string& n, Weapon& w);
		~HumanA();
		void attack() const;
};
