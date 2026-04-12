/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 12:01:29 by ikozhina          #+#    #+#             */
/*   Updated: 2026/04/11 16:45:22 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter& operator=(const ScalarConverter& src);
        ~ScalarConverter();

        static bool isPseudoLiterals(const std::string& literal);
        static bool isChar(const std::string& literal);
        static bool isFloat(const std::string& literal);
        static bool isDouble(const std::string& literal);
        
        static void convertFromChar(const std::string& literal);
        static void convertFromFloat(const std::string& literal);
        static void convertFromDouble(const std::string& literal);
        static void convertFromInt(const std::string& literal);
        static void printPseudoLiterals(const std::string& literal);
        static void printResults(double d);
        static void printImpossible();

    public:
        static void convert(const std::string& value);
};

/* 1. is pseudo-literal → float or double
2. starts/ends with ' → char
3. ends with 'f', contains '.' → float
4. contains '.' → double
5. otherwise → int */