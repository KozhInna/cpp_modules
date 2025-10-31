/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:31:47 by ikozhina          #+#    #+#             */
/*   Updated: 2025/10/31 21:40:17 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

bool    isEmpty(const std::string& str)
{
    if (str.empty())
        return (true);
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isspace(static_cast<unsigned char>(str[i])))
            return (false);
    }
    return (true);
}

std::string promptContactInfo(const std::string& field)
{
    std::string input;
    
    while (true)
    {
        std::cout << field << ":" << std::endl;
        std::getline(std::cin, input);
        if (isEmpty(input))
        {
            std::cout << "Field can't be empty" << std::endl;
            continue ;   
        }
        break ;
    }
    return (input);
}

void    handleAdd(PhoneBook& phonebook)
{
    Contact newContact;

    newContact.setFirstName(promptContactInfo("First name"));
    newContact.setLastName(promptContactInfo("Last name"));
    newContact.setNickname(promptContactInfo("Nickname"));
    newContact.setPhoneNumber(promptContactInfo("Phone number"));
    newContact.setDarkestSecret(promptContactInfo("Darkest secret"));
    
    phonebook.addContact(newContact);
}

int main(void)
{
    PhoneBook phonebook;
    std::string input;

    while (true)
    {
        std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
        std::getline(std::cin, input);
        if (input == "EXIT")
            return (0);
        else if (input == "SEARCH")
        {
            phonebook.displayContacts();
        }
            // std::cout << "You entered SEARCH" << std::endl;
        else if (input == "ADD")
            handleAdd(phonebook);
    }

    
        // Read user commands (ADD, SEARCH, EXIT)
        // Call PhoneBook methods based on commands

        // main → prompts user → user types "SEARCH"
        // main → calls phonebook.displayAllContacts()
        //     → phonebook uses contact.getFirstName() for each contact
        // main → prompts for index
        // main → calls phonebook.getContact(index)
        //     → displays that contact's info
    return (0);
}
