/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:54:07 by ikozhina          #+#    #+#             */
/*   Updated: 2025/10/31 21:58:10 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
    
    private:
        Contact contacts[8];
        int numContacts;

    public:
        PhoneBook() : numContacts(0) {}
        void setNumContacts();
        void addContact(const Contact& contact);
        void displayContacts();
        
    //how many stored
    //which one is the oldest - circular buffer
    //add contact
    //search contact
    //display contact
    //get a specific by index
};

#endif