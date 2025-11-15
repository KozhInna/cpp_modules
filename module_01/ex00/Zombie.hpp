/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:33:19 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/15 10:36:27 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		Zombie(std::string zombieName);
		~Zombie();
		void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);