/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:58:18 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/05 14:15:45 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const std::string& type);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void makeSound() const;
};