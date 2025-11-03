/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:54:07 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/03 15:27:07 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook {

	private:
		Contact contacts[8];
		int numContacts;
		int nextIndex;

	public:
		PhoneBook();
		void addContact(const Contact& contact);
		void displayContacts();
		void displayContactInfo(int index);
		int	getNumContacts() const;
};

#endif