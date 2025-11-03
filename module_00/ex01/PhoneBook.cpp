/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:51:15 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/03 15:30:08 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : numContacts(0), nextIndex(0) {}

static std::string truncate(const std::string& str)
{
	if (str.length() > 10)
	{
		return (str.substr(0, 9) + ".");
	}
	return str;
}

void PhoneBook::addContact(const Contact& contact)
{
	contacts[nextIndex] = contact;
	nextIndex = (nextIndex + 1) % 8;
	if (numContacts < 8)
		numContacts++;
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
		<< std::setw(10) << std::right << truncate(contacts[i].getFirstName()) << "|"
		<< std::setw(10) << std::right << truncate(contacts[i].getLastName()) << "|"
		<< std::setw(10) << std::right << truncate(contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::displayContactInfo(int index)
{
	std::cout << "First name: ";
	std::cout << contacts[index - 1].getFirstName() << std::endl;
	std::cout << "Last name: ";
	std::cout << contacts[index - 1].getLastName() << std::endl;
	std::cout << "Nickname: ";
	std::cout << contacts[index - 1].getNickname() << std::endl;
	std::cout << "Phone number: ";
	std::cout << contacts[index - 1].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: ";
	std::cout << contacts[index - 1].getDarkestSecret() << std::endl;
}
int PhoneBook::getNumContacts() const
{
	return numContacts;
}