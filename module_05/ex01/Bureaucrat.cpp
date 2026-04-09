/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:26:06 by ikozhina          #+#    #+#             */
/*   Updated: 2026/04/09 09:40:53 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << "\033[1;30m" << name_ << " signed " << form.getName() << "\033[0m" << std::endl;
    } catch (std::exception& e) {
        std::cout << "\033[1;30m" << name_ << " couldn't sign " << form.getName() <<
            " because " << e.what() << "\033[0m" << std::endl;
    } 
}

Bureaucrat::Bureaucrat(const std::string& n, int g) : name_(n), grade_(g) {
    std::cout << "Bureaucrat parametarised constructor called" << std::endl;
    if (grade_ < 1) {
        throw GradeTooHighException();
    }
    if (grade_ > 150) {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name_(other.name_), grade_(other.grade_) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat copy assignment operator" << std::endl;
    if (this != &other) {
        grade_ = other.grade_;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string& Bureaucrat::getName() const {
    return name_;
}

int Bureaucrat::getGrade() const {
    return grade_;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return "Above possible top grade";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return "Below possible bottom grade";
}

void Bureaucrat::incrementGrade() {
    if (grade_ == 1) {
        throw GradeTooHighException();
    }
    grade_--;
}

void Bureaucrat::decrementGrade() {
    if (grade_ == 150) {
        throw GradeTooLowException();
    }
    grade_++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}