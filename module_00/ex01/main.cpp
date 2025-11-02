/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:31:47 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/02 23:34:30 by ikozhina         ###   ########.fr       */
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
bool isNumber(std::string& input)
{
    for (char c : input)
    {
        if (!std::isdigit(c))
            return (false);
    }
    return (true);
}

void    handleSearch(PhoneBook& phonebook)
{
    std::string input;
    
    phonebook.displayContacts();
    if (phonebook.getNumContacts() == 0)
        return ;
    std::cout << "Specify an index" << std::endl;
    std::getline(std::cin, input);
    if (input.empty() || !isNumber(input))
    {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    try
    {    
        int index = std::stoi(input);
        if (index < 1 || index > phonebook.getNumContacts())
        {    
            std::cout << "Invalid index" << std::endl;
            return; 
        }
        phonebook.displayContactInfo(index);
    }
    catch (const std::exception& e)
    {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
}

//treat spaces after and before ADD and other prompts

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
            handleSearch(phonebook);
        else if (input == "ADD")
            handleAdd(phonebook);
    }
    return (0);
}
