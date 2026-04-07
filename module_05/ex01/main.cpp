/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:26:01 by ikozhina          #+#    #+#             */
/*   Updated: 2026/03/26 14:59:52 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(){
    std::cout << std::endl << "=== Constructors & destructors & operators ===" << std::endl;
	{
        try {
            Form f1("Form1", 25, 100);
            std::cout << f1 << std::endl;
            
            Form f2 = f1;
            std::cout << f2 << std::endl;
        } 
        catch(const std::exception& e) {
            std::cout << "Exception caught - " << e.what() << std::endl;        
        }
    }
    
    std::cout << std::endl << "=== Grade too low ===" << std::endl;
    {
        try {
            Form f1("Form1", 151, 100);
        }
        catch(const std::exception& e) {
            std::cout << "Exception caught - " << e.what() << std::endl;
        } 
        try {
            Form f1("Form1", 15, 160);
        }
        catch(const std::exception& e) {
            std::cout << "Exception caught - " << e.what() << std::endl;
        } 
    }
    
    std::cout << std::endl << "=== Grade too high ===" << std::endl;
    {
        try {
            Form f1("Form1", 15, 0);
        }
        catch(const std::exception& e) {
            std::cout << "Exception caught - " << e.what() << std::endl;
        } 
        try {
            Form f1("Form1", -1, 100);
        }
        catch(const std::exception& e) {
            std::cout << "Exception caught - " << e.what() << std::endl;
        } 
	}

    std::cout << std::endl << "=== Sign Form ===" << std::endl;
    {        
        try {
            Form f1("Alert form", 26, 100);
            std::cout << f1 << std::endl;
            Bureaucrat b1("Tim", 25);
            std::cout << b1 << std::endl;
            
            b1.signForm(f1);
            std::cout << f1 << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Exception caught - " << e.what() << std::endl;
        }
        std::cout << std::endl;
        try {
            Form f1("Wrong form", 30, 100);
            std::cout << f1 << std::endl;
            Bureaucrat b1("Tom", 35);
            std::cout << b1 << std::endl;
            
            b1.signForm(f1);
        }
        catch (const std::exception& e) {
            std::cout << "Exception caught " << e.what() << std::endl;
        }
    }
    return 0;
}