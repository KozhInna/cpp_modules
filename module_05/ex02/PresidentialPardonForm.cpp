#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	target_(target), AForm("PresidentialPardonForm", 25, 5) {
	std::cout << "PresidentialPardonForm parametarised constructor called" << std::endl;
}