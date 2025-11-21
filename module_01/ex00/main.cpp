/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:33:04 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/21 09:40:09 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	std::cout << "--- ZOMBIE ON HEAP ---" << std::endl;
	Zombie* ptrZombie = newZombie("ZzzHeap");
	ptrZombie->announce();
	delete ptrZombie;
	std::cout << "\n--- ZOMBIE ON STACK ---" << std::endl;
	randomChump("ZzzStack");
	return 0;
}