/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:57:14 by ikozhina          #+#    #+#             */
/*   Updated: 2026/03/26 14:55:57 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(const std::string& n, int gradeSign, int grageExec) :
    name_(n), 
    isSigned_(false), 
    gradePassToSign_(gradeSign), 
    gradePassToExecute_(grageExec) {
    std::cout << "Form parametarised constructor called" << std::endl;
    if (gradePassToSign_ < 1 || gradePassToExecute_ < 1) {
        throw GradeTooHighException();
    }
    if (gradePassToSign_ > 150 || gradePassToExecute_ > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(const Form& other) : 
    name_(other.name_), 
    isSigned_(other.isSigned_), 
    gradePassToSign_(other.gradePassToSign_), 
    gradePassToExecute_(other.gradePassToExecute_) {
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
    std::cout << "Form copy assignment operator" << std::endl;
    if (this != &other) {
        isSigned_ = other.isSigned_;    
    }
    return *this;
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

const std::string& Form::getName() const {
    return name_;
}

bool Form::getIsSigned() const {
    return isSigned_;
}

int Form::getGradePassToSign() const {
    return gradePassToSign_;
}

int Form::getGradePassToExecute() const {
    return gradePassToExecute_;
}

const char* Form::GradeTooHighException::what()const noexcept {
    return "Above possible top grade";
}

const char* Form::GradeTooLowException::what() const noexcept {
    return "Below possible bottom grade";
}
   
void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= gradePassToSign_) {
        isSigned_ = true;
    } else {
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName() << (f.getIsSigned() ? " is signed." : " isn't signed.") << "\n";
    os << "Grade required to sign it - " << f.getGradePassToSign() << "\n";
    os << "Grade required to execute it - " << f.getGradePassToExecute();
    return os;
}
