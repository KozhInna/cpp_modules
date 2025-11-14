/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:33:04 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/14 23:15:06 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main()
{
	std::cout << "\nZOMBIE ON HEAP\n" << std::endl;
	Zombie* ptrZombie = newZombie("ZzzHeap");
	ptrZombie->announce();
	delete ptrZombie;
	std::cout << '\n' << std::string(30, '-') << std::endl;
	std::cout << "\nZOMBIE ON STACK\n" << std::endl;
	randomChump("ZzzStack");
	std::cout << std::endl;
	return 0;
}