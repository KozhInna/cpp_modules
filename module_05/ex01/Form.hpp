/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:49:38 by ikozhina          #+#    #+#             */
/*   Updated: 2026/03/26 14:14:54 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <ostream>

class Bureaucrat;

class Form {
    private:
        const std::string name_;
        bool isSigned_;
        const int gradePassToSign_;
        const int gradePassToExecute_;
    
    public:
        Form() = delete;
        ~Form();
        Form(const std::string& n, int gradeSign, int grageExec);
        Form(const Form& other);
        Form& operator=(const Form& other);

        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradePassToSign() const;
        int getGradePassToExecute() const;
        void beSigned(const Bureaucrat& b);

        class GradeTooHighException : public std::exception {
            public:
                const char* what()const noexcept override;
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const noexcept override;
        };
        
};

std::ostream& operator<<(std::ostream& os, const Form& f);