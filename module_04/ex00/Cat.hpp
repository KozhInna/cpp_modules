/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:19:10 by ikozhina          #+#    #+#             */
/*   Updated: 2025/12/05 13:57:41 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const std::string& type);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		void makeSound() const;
};