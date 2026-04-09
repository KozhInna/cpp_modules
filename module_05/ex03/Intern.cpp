/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:39:22 by ikozhina          #+#    #+#             */
/*   Updated: 2026/04/09 16:32:10 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& src) {
    (void)src;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& src) {
    (void)src;
    std::cout << "Intern copy assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string formName, const std::string target) const {
    std::string forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};

    for (int i = 0; i < 3; i++) {
        if (forms[i] == formName) {     
            std::cout << "\033[1;30m" << "Intern creates " << formName << "\033[0m" << std::endl;       
            switch(i)
            {                
                case 0:
                    return new RobotomyRequestForm(target);
                case 1:
                    return new ShrubberyCreationForm(target);
                case 2:
                    return new PresidentialPardonForm(target);
            }   
        }
    }
    std::cout << "Form " << formName << " does not exist" << std::endl;
    return nullptr;
}