/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:49:29 by ikozhina          #+#    #+#             */
/*   Updated: 2026/04/09 11:32:54 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
    AForm("RobotomyRequestForm", 72, 45), target_(target) {
    std::cout << "RobotomyRequestForm parametarised constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) :
    AForm(src), target_(src.target_) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    if (this != &src) {
        AForm::operator=(src);
        target_ = src.target_;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::executeImpl() const {
    std::cout << "BZZzzz" << std::endl; 

    if (std::rand() % 2)
        std::cout << target_ << " has been robotomized successfully." << std::endl;
    else
        std::cout << target_ << " robotomy failed." << std::endl;
}