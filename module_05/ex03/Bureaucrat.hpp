/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:26:09 by ikozhina          #+#    #+#             */
/*   Updated: 2026/04/07 14:42:53 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <ostream>

class AForm; // forward declaration to avoid circular include

class Bureaucrat {
    public:
        Bureaucrat() = delete;
        ~Bureaucrat();
        Bureaucrat(const std::string& n, int g);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);

        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm& form);

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const noexcept override;
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const noexcept override;
        };

		void executeForm(AForm const& form) const;

    private:
        const std::string name_;
        int grade_;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
