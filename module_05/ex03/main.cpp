/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:26:01 by ikozhina          #+#    #+#             */
/*   Updated: 2026/04/09 16:49:57 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <ctime>

int main(){
    std::srand(std::time(nullptr));
   
    Intern someIntern;

    std::cout << "\n=== Robotomy request ===" << std::endl;
    AForm* robotomyF = someIntern.makeForm("robotomy request", "Bender");
    if (robotomyF) {
        std::cout << *robotomyF << std::endl;
        try {
            Bureaucrat b1("Bob", 1);
            b1.signForm(*robotomyF);
            std::cout << *robotomyF << std::endl;
            b1.executeForm(*robotomyF);
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        delete robotomyF;
    }

    std::cout << "\n=== Shrubbery creation ===" << std::endl;
    AForm* shrubberyF = someIntern.makeForm("shrubbery creation", "Garden");
    if (shrubberyF) {
        std::cout << *shrubberyF << std::endl;
        try {
            Bureaucrat b2("Alice", 1);
            b2.signForm(*shrubberyF);
            std::cout << *shrubberyF << std::endl;
            b2.executeForm(*shrubberyF);
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        delete shrubberyF;
    }

    std::cout << "\n=== Presidential pardon ===" << std::endl;
    AForm* presidentialF = someIntern.makeForm("presidential pardon", "John");
    if (presidentialF) {
        std::cout << *presidentialF << std::endl;
        try {
            Bureaucrat b3("Tom", 1);
            b3.signForm(*presidentialF);
            std::cout << *presidentialF << std::endl;
            b3.executeForm(*presidentialF);
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        delete presidentialF;
    }

    std::cout << "\n=== Invalid form name ===" << std::endl;
    AForm* invalid = someIntern.makeForm("random request", "Intern");
    if (!invalid)
        std::cout << "Correctly returned nullptr for unknown form" << std::endl;
    
    return 0;
}
