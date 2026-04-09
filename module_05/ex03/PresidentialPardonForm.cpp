#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("PresidentialPardonForm", 25, 5), target_(target) {
	std::cout << "PresidentialPardonForm parametarised constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) :
    AForm(src), target_(src.target_) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
    std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    if (this != &src) {
        AForm::operator=(src);
        target_ = src.target_;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::executeImpl() const {
    std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}