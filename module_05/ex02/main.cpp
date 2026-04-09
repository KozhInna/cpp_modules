/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:26:01 by ikozhina          #+#    #+#             */
/*   Updated: 2026/04/09 16:55:16 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <ctime>

int main(){
    std::srand(std::time(nullptr));

    std::cout << std::endl << "=== Constructors & destructors & operators ===" << std::endl;
    try {
        PresidentialPardonForm presidentForm("James");
        RobotomyRequestForm robotForm("Walle");
        ShrubberyCreationForm shrubberyForm("Garden");
        std::cout << "Forms: \n" << shrubberyForm << "\n" << robotForm << "\n" <<  
        presidentForm << std::endl;
    } catch(const std::exception& e) {
        std::cout << "Exception caught - " << e.what() << std::endl;
    }

    try {
            Bureaucrat b1("Tom", 4);
            std::cout << std::endl << "=== Execute unsigned Form ===" << std::endl;
        {
            PresidentialPardonForm presidentForm("James");
            b1.executeForm(presidentForm);
        }
        {
            RobotomyRequestForm robotForm("Walle");
            b1.executeForm(robotForm);
        }
        {
            ShrubberyCreationForm shrubberyForm("Garden");
            b1.executeForm(shrubberyForm);
        }
        std::cout << std::endl << "=== Execute signed Form ===" << std::endl;
        {
            PresidentialPardonForm presidentForm("James");
            b1.signForm(presidentForm);
            b1.executeForm(presidentForm);
        }
        {
            RobotomyRequestForm robotForm("Walle");
            b1.signForm(robotForm);
            for (int i = 0; i < 5; i++)
                b1.executeForm(robotForm);
        }
        {
            ShrubberyCreationForm shrubberyForm("Garden");
            b1.signForm(shrubberyForm);
            b1.executeForm(shrubberyForm);
        }
    } catch(const std::exception& e) {
        std::cout << "Exception caught - " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Two bureaucrats: sign and execute ===" << std::endl;

    try {        
        Bureaucrat b2("Joe", 4);
        Bureaucrat b3("John", 26);

        {        
            ShrubberyCreationForm shrubbery("Cherry");
            b2.signForm(shrubbery);
            b3.executeForm(shrubbery);  
        }
    std::cout << std::endl;
        {       
            RobotomyRequestForm robot("Chair");
            b2.signForm(robot);
            b3.executeForm(robot);     
            b2.executeForm(robot);
            b3.executeForm(robot);
        }
    std::cout << std::endl;
        {       
            PresidentialPardonForm pardon("Smith");
            b2.signForm(pardon);
            b3.executeForm(pardon);     
            b2.executeForm(pardon);     
        }
    } catch(const std::exception& e) {
        std::cout << "Exception caught - " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {       
        Bureaucrat low("Low", 150);
        PresidentialPardonForm pardon2("Smith");
        low.signForm(pardon2);      
        low.executeForm(pardon2); 
    } catch(const std::exception& e) {
        std::cout << "Exception caught - " << e.what() << std::endl;
    }

    return 0;
}
