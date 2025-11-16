/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:55:59 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/16 22:30:13 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type_(type) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const
{
    return type_;
}

void Weapon::setType(const std::string& newType)
{
    type_ = newType;
}
