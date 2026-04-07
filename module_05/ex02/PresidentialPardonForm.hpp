/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:08:57 by ikozhina          #+#    #+#             */
/*   Updated: 2026/04/07 14:50:36 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
	private:
		std::string target_;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
		virtual ~PresidentialPardonForm();

		void executeImpl(Bureaucrat const& executor) const override;
		PresidentialPardonForm(const std::string& target);
};