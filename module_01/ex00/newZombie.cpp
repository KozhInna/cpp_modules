/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:33:11 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/13 11:03:14 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* newZombie(std::string name)
{
	return new Zombie(name);
}
