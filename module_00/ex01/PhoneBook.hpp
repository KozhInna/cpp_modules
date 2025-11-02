/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:54:07 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/02 12:50:24 by ikozhina         ###   ########.fr       */
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
        void displayContactInfo(int index);
        int getNumContacts() const;
};

#endif