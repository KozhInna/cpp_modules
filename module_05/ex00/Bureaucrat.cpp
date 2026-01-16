/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:25:46 by ikozhina          #+#    #+#             */
/*   Updated: 2026/01/16 15:15:01 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include<string>
#include<iostream>

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name), grade_(grade) {
	std::cout << "Bureaucrat param constructor" << std::endl;
	if (grade_ < 1 || grade_ > 150) {
		throw std::out_of_range("Grade must be between 1 and 150");
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name_(other.name_), grade_(other.grade_) {
	std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
	std::cout << "Bureaucrat copy assignment operator" << std::endl;
	if(this != &other) {
		grade_ = other.grade_;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor" << std::endl;
}