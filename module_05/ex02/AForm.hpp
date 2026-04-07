/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:49:38 by ikozhina          #+#    #+#             */
/*   Updated: 2026/04/07 14:48:18 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <ostream>

class Bureaucrat;

class AForm {
    private:
        const std::string name_;
        bool isSigned_;
        const int gradePassToSign_;
        const int gradePassToExecute_;

    public:
        AForm() = delete;
        virtual ~AForm();
        AForm(const std::string& n, int gradeSign, int grageExec);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

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

		void execute(Bureaucrat const& executor) const;

		protected:
			virtual void executeImpl(Bureaucrat const& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);