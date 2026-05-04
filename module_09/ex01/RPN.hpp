#pragma once

#include <stack>
#include <string>

class RPN {
    private:
        std::stack<long> stack_;

        void validateAndCalculate(const std::string& input);

    public:
        RPN() = delete;
        RPN(const std::string& input);
        RPN(const RPN& src) = default;
        RPN& operator=(const RPN& src) = default;
        ~RPN() = default;

        int getResult() const;
};