/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:57:14 by ikozhina          #+#    #+#             */
/*   Updated: 2026/03/26 14:55:57 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(const std::string& n, int gradeSign, int grageExec) :
    name_(n),
    isSigned_(false),
    gradePassToSign_(gradeSign),
    gradePassToExecute_(grageExec) {
    std::cout << "AForm parametarised constructor called" << std::endl;
    if (gradePassToSign_ < 1 || gradePassToExecute_ < 1) {
        throw GradeTooHighException();
    }
    if (gradePassToSign_ > 150 || gradePassToExecute_ > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& other) :
    name_(other.name_),
    isSigned_(other.isSigned_),
    gradePassToSign_(other.gradePassToSign_),
    gradePassToExecute_(other.gradePassToExecute_) {
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    std::cout << "AForm copy assignment operator" << std::endl;
    if (this != &other) {
        isSigned_ = other.isSigned_;
    }
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

const std::string& AForm::getName() const {
    return name_;
}

bool AForm::getIsSigned() const {
    return isSigned_;
}

int AForm::getGradePassToSign() const {
    return gradePassToSign_;
}

int AForm::getGradePassToExecute() const {
    return gradePassToExecute_;
}

const char* AForm::GradeTooHighException::what()const noexcept {
    return "Above possible top grade";
}

const char* AForm::GradeTooLowException::what() const noexcept {
    return "Below possible bottom grade";
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= gradePassToSign_) {
        isSigned_ = true;
    } else {
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getName() << (f.getIsSigned() ? " is signed." : " isn't signed.") << "\n";
    os << "Grade required to sign it - " << f.getGradePassToSign() << "\n";
    os << "Grade required to execute it - " << f.getGradePassToExecute();
    return os;
}
