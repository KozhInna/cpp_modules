/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 12:26:36 by ikozhina          #+#    #+#             */
/*   Updated: 2026/04/12 17:16:52 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        printImpossible();
        return;
    }
    if (isPseudoLiterals(literal)) {
        printPseudoLiterals(literal);
        return ;
    }
    if (isChar(literal)) {
        convertFromChar(literal);
        return ;
    }
    if (isFloat(literal)) {
        convertFromFloat(literal);
        return ;
    }
    if (isDouble(literal)) {
        convertFromDouble(literal);
        return ;
    }
    convertFromInt(literal);
}

void ScalarConverter::printImpossible() {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convertFromInt(const std::string& literal) {
    try {
        int i = std::stoi(literal);
        printResults(i);
    } catch (std::exception&) {
        printImpossible();
    }
}

void ScalarConverter::convertFromFloat(const std::string& literal) {
    try {
        float f = std::stof(literal); 
        printResults(f);
    } catch (std::exception&) {
        printImpossible();
    }
}

void ScalarConverter::convertFromDouble(const std::string& literal) {
    try {
        double d = std::stod(literal); 
        printResults(d);
    } catch (std::exception&) {
        printImpossible();
    }     
}

bool ScalarConverter::isFloat(const std::string& literal) {
    return literal[literal.size() - 1] == 'f' && 
     literal.find('.') != std::string::npos;
}

bool ScalarConverter::isDouble(const std::string& literal) {
    return literal.find('.') != std::string::npos;
}

void ScalarConverter::convertFromChar(const std::string& literal) {
    char c = literal[0];

    printResults(c);
}

void ScalarConverter::printResults(double d) {
    // char
    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint((unsigned char)static_cast<int>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

    // int
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    // float
    float fval = static_cast<float>(d);
    if (std::isinf(fval) && !std::isinf(d))
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << fval << "f" << std::endl;

    // double
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::printPseudoLiterals(const std::string& literal) {
    std::string f, d;
    
    if (literal == "nan" || literal == "nanf") {
        f = "nanf";
        d = "nan";
    } else if (literal == "+inf" || literal == "+inff") {
        f = "+inff";
        d = "+inf";
    } else if (literal == "-inf" || literal == "-inff") {
        f = "-inff";
        d = "-inf";
    }
    
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
}

bool ScalarConverter::isPseudoLiterals(const std::string& literal) {
    return (literal == "-inf" || literal == "+inf" || literal == "nan" ||
        literal == "-inff" || literal == "+inff" || literal == "nanf");
}

bool ScalarConverter::isChar(const std::string& literal) {
    return literal.size() == 1 && !std::isdigit((unsigned char)literal[0]);
}

