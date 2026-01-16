/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:25:44 by ikozhina          #+#    #+#             */
/*   Updated: 2026/01/16 15:09:32 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<string>

class Bureaucrat
{
	public:
		Bureaucrat() = delete;
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();

	private:
		const std::string name_;
		int grade_;
};