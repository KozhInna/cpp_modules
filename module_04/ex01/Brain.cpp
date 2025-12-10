/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:05:30 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/10 12:25:15 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas_[i] = other.ideas_[i];
	}
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas_[i] = other.ideas_[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		ideas_[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return ideas_[index];
	return "";
}