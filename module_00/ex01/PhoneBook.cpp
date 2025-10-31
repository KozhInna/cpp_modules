/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:51:15 by ikozhina          #+#    #+#             */
/*   Updated: 2025/10/31 23:31:04 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

void PhoneBook::setNumContacts()
{
    numContacts++; 
}

void PhoneBook::addContact(const Contact& contact)
{
    contacts[numContacts % 8] = contact;
    setNumContacts();
}



void PhoneBook::displayContacts()
{
    std::cout << std::setw(10) << std::right << "Index" << "|"
              << std::setw(10) << std::right << "First name" << "|"
              << std::setw(10) << std::right << "Last name" << "|"
              << std::setw(10) << std::right << "Nickname" << std::endl;
    for (int i = 0; i < numContacts; i++)
    {
        std::cout << std::setw(10) << std::right << (i + 1) << "|"
        << std::setw(10) << std::right << contacts[i].getFirstName() << "|"
        << std::setw(10) << std::right << contacts[i].getLastName() << "|"
        << std::setw(10) << std::right << contacts[i].getNickname() << std::endl;
    }
}

static std::string formatField(const std::string& str)
{
    if (str.length() > 10)
    {
        // truncate and add dot
        // hint: use str.substr(0, 9) + "."
    }
    return str;
}