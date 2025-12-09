/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:07:34 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/09 12:59:29 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

	Dog::Dog() : Animal("Dog")
	{
		std::cout << "Dog default constructor" << std::endl;
        brain_ = new Brain();
	}

	Dog::Dog(const Dog& other) : Animal(other), brain_(nullptr)
	{
		std::cout << "Dog copy constructor" << std::endl;
        brain_ = new Brain(*other.brain_);
	}

	Dog& Dog::operator=(const Dog& other)
	{
		std::cout << "Dog assignment operator" << std::endl;
		if (this != &other)
        {
			Animal::operator=(other);
            delete brain_;
            brain_ = new Brain(*other.brain_);    
        }
		return *this;
	}
	Dog::~Dog()
	{
		std::cout << "Dog destructor" << std::endl;
        delete brain_;
	}

	void Dog::makeSound() const
	{
		std::cout << type_ << " is barking" << std::endl;
	}