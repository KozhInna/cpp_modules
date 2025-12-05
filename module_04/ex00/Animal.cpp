/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:30:41 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/05 13:28:11 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type_("unnamed")
{
	std::cout << "Animal calls default constructor" << std::endl;
}

Animal::Animal(const std::string& type) : type_(type)
{
	std::cout << "Animal calls param constructor" << std::endl;
}

Animal::Animal(const Animal& other) : type_(other.type_)
{
	std::cout << "Animal calls copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal calls copy assignment operator" << std::endl;
	if (this != &other)
		type_ = other.type_;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal calls destructor" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Generic animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return type_;
}