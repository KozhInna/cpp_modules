#include "BitcoinExchange.hpp"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange(const std::string& fileName) {
    loadData(fileName);
}

void BitcoinExchange::loadData(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open .csv file.");
    }

    std::string str;
    while (std::getline(file, str)) {
		std::stringstream ss(str);
        std::string date, value;
        std::getline(ss, date, ',');
        std::getline(ss, value);
        date = trim(date);
		if (date.empty() || !isdigit(date[0]))
			continue;
		if (!validateDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
        try {
            data_.insert({date, std::stof(value)});
        } catch (const std::exception& e) {
            std::cerr << "Error: invalid value in database: " << e.what() << std::endl;
        }
    }
	if (data_.empty())
		throw std::runtime_error("Error: empty database.");
}

std::string BitcoinExchange::trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    return (start == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

void BitcoinExchange::countBitcoins(std::ifstream& file) {
    std::string str;

    while (std::getline(file, str)) {
        std::stringstream ss(str);
        std::string date, value;
        std::getline(ss, date, '|');
        std::getline(ss, value);
        date = trim(date);
		if (!isdigit(date[0]))
			continue;
		if (!validateDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
        if (value.empty()) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        double num;
        try {
            num  = std::stof(value);
        } catch (const std::exception& e) {
            std::cerr << "Error: invalid value in input file: " << e.what() << std::endl;
            continue;
        }
        if (num < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (num > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        auto it = data_.lower_bound(date);
        if (it == data_.begin() && it->first != date) {
            std::cerr << "Error: bad input => " << date << std::endl;
        } else if (it != data_.end() && it->first == date) {
            std::cout << date << " => " << num << " = " << (it->second * num) << std::endl;
        } else {
            --it;
            std::cout << date << " => " << num << " = " << (it->second * num) << std::endl;
        }
    }
}

//2012-01-11
bool BitcoinExchange::validateDate(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-'){
		return false;
	}
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}
	int month = std::stoi(date.substr(5, 2));
	if (month < 1 || month > 12)
    	return false;

	int day = std::stoi(date.substr(8, 2));
	if (day < 1 || day > 31)
    	return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int year = std::stoi(date.substr(0, 4));
	bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	if (isLeap) daysInMonth[1] = 29;

	return day <= daysInMonth[month - 1];
}