/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:17:47 by ikozhina          #+#    #+#             */
/*   Updated: 2025/10/31 12:37:37 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName() const
{
    return firstName;  
} 

std::string Contact::getLastName() const
{
    return lastName;
}
    
std::string Contact::getNickname() const
{
    return nickname;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}

void Contact::setFirstName(const std::string& name)
{
    firstName = name;
}

void Contact::setLastName(const std::string& name)
{
    lastName = name;
}

void Contact::setNickname(const std::string& name)
{
    nickname = name;
}

void Contact::setPhoneNumber(const std::string& number)
{
    phoneNumber = number;
}

void Contact::setDarkestSecret(const std::string& secret)
{
    darkestSecret = secret;
}