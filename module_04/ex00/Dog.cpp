/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:07:34 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/05 14:21:20 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

	Dog::Dog() : Animal("Dog")
	{
		std::cout << "Dog default constructor" << std::endl;
	}

	Dog::Dog(const std::string& type) : Animal(type)
	{
		std::cout << "Dog param constructor" << std::endl;
	}

	Dog::Dog(const Dog& other) : Animal(other)
	{
		std::cout << "Dog copy constructor" << std::endl;
	}

	Dog& Dog::operator=(const Dog& other)
	{
		std::cout << "Dog assign operator constructor" << std::endl;
		if (this != &other)
			Animal::operator=(other);
		return *this;
	}
	Dog::~Dog()
	{
		std::cout << "Dog destructor" << std::endl;
	}

	void Dog::makeSound() const
	{
		std::cout << "Dog is barking" << std::endl;
	}