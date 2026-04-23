#pragma once

#include <map>
#include <string>

class BitcoinExchange {
    private:
        std::map<std::string, float> data_;

        void loadData(const std::string& file);
        static std::string trim(const std::string& s);
		static bool validateDate(const std::string& s);

    public:
        BitcoinExchange() = delete;
        BitcoinExchange(const std::string& fileName);
        BitcoinExchange(const BitcoinExchange& src) = default;
        BitcoinExchange& operator=(const BitcoinExchange& src) = default;
        ~BitcoinExchange() = default;

        void countBitcoins(std::ifstream& file);
};