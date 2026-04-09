/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 20:11:08 by ikozhina          #+#    #+#             */
/*   Updated: 2026/04/09 11:32:59 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
    AForm("ShrubberyCreationForm", 145, 137), target_(target) {
    std::cout << "ShrubberyCreationForm parametarised constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) :
    AForm(src), target_(src.target_) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    if (this != &src) {
        AForm::operator=(src);
        target_ = src.target_;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::executeImpl() const {
    std::ofstream newFile(target_ + "_shrubbery");
    if (!newFile.is_open())
        throw std::runtime_error("Could not open file");
        
    newFile << "      *      " << "\n";
    newFile << "     ***     " << "\n";
    newFile << "    *****    " << "\n";
    newFile << "   *******   " << "\n";
    newFile << "  *********  " << "\n";
    newFile << "     | |     " << "\n";
    newFile << "     | |     " << "\n";
    newFile.close();
}
