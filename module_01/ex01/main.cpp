/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:41:06 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/21 09:33:42 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	int N = 3;
	std::cout << "--- Creating zombie horde ---" << std::endl;
	Zombie* horde = zombieHorde(N, "Bzz");
	std::cout << "\n--- Zombie announcing ---" << std::endl;
	for (int i = 0; i < N; i++)
		horde[i].announce();
	std::cout << "\n--- Deleting zombie horde ---" << std::endl;
	delete[] horde;
	return 0;
}