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
    
    std::getline(file, str); 
    while (std::getline(file, str)) {
        std::stringstream ss(str);
        std::string date, value;
        std::getline(ss, date, ',');
        std::getline(ss, value);
        date = trim(date);
        try {
            data_.insert({date, std::stof(value)});
        } catch (const std::exception& e) {
            std::cerr << "Error: invalid value in database: " << e.what() << std::endl;
        }
    }
    file.close();
}

std::string BitcoinExchange::trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    return (start == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

void BitcoinExchange::countBitcoins(std::ifstream& file) {
    std::string str;
    
    std::getline(file, str); 
    while (std::getline(file, str)) {
        std::stringstream ss(str);
        std::string date, value;
        std::getline(ss, date, '|');
        std::getline(ss, value);
        date = trim(date);
        if (value.empty()) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        float num;
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
        } else if ((it != data_.end() && it->first != date) || (it == data_.end()) ){
            --it;
            std::cout << date << " => " << num << " = " << (it->second * num) << std::endl;
        }
    }

}