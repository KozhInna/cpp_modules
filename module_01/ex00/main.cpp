/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:33:04 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/15 10:43:35 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main()
{
	std::cout << "--- ZOMBIE ON HEAP ---" << std::endl;
	Zombie* ptrZombie = newZombie("ZzzHeap");
	ptrZombie->announce();
	delete ptrZombie;
	// std::cout << '\n' << std::string(30, '-') << std::endl;
	std::cout << "\n--- ZOMBIE ON STACK ---" << std::endl;
	randomChump("ZzzStack");
	std::cout << std::endl;
	return 0;
}