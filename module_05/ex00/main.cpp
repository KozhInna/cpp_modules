/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:26:01 by ikozhina          #+#    #+#             */
/*   Updated: 2026/03/26 15:00:02 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(){
    std::cout << std::endl << "=== Constructors & destructors & operators ===" << std::endl;
	{
        try {
            Bureaucrat b1("Tim", 25);
            std::cout << b1 << std::endl;
            
            Bureaucrat b2 = b1;
            std::cout << b2 << std::endl;
            
            Bureaucrat b3("Anna", 100);
            std::cout << b3 << std::endl;
            b3 = b2;
            std::cout << b3 << std::endl;

        } 
        catch(const std::exception& e) {
            std::cout << "Exception caught - " << e.what() << std::endl;
        }
    }
    
    std::cout << std::endl << "=== Grade too low ===" << std::endl;
    {
        try {
            Bureaucrat b3("Tom", 250);
        }
        catch(const std::exception& e) {
            std::cout << "Exception caught - " << e.what() << std::endl;
        } 
    }
    
    std::cout << std::endl << "=== Grade too high ===" << std::endl;
    {
        try {
            Bureaucrat b4("Dan", 0);
        }
        catch(const std::exception& e) {
            std::cout << "Exception caught - " << e.what() << std::endl;
        }
	}

    std::cout << std::endl << "=== Increment Grade ===" << std::endl;
    {        
        try {
            Bureaucrat b1("Tim", 25);
            std::cout << b1 << std::endl;
            
            b1.incrementGrade();
            std::cout << b1 << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Exception caught - " << e.what() << std::endl;
        }
        std::cout << std::endl;
        try {
            Bureaucrat b1("Tim", 1);
            std::cout << b1 << std::endl;
            
            b1.incrementGrade();
            std::cout << b1 << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Exception caught - " << e.what() << std::endl;
        }
    }
    
    std::cout << std::endl << "=== Decrement Grade ===" << std::endl;
    {        
        try {
            Bureaucrat b1("Tim", 25);
            std::cout << b1 << std::endl;
            
            b1.decrementGrade();
            std::cout << b1 << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Exception caught - " << e.what() << std::endl;
        }
        std::cout << std::endl;
        try {
            Bureaucrat b1("Tim", 150);
            std::cout << b1 << std::endl;
            
            b1.decrementGrade();
            std::cout << b1 << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Exception caught - " << e.what() << std::endl;
        }
    }
    return 0;
}