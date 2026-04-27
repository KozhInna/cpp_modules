#include "RPN.hpp"
#include <sstream>


RPN::RPN(const std::string& input) {
    validateAndCalculate(input);
}

void RPN::validateAndCalculate(const std::string& input) {
    if (input.empty()) throw std::runtime_error("Error: input empty.");

    std::istringstream iss(input);
    std::string token;
    while (iss >> token) {
        if (token.size() == 1 && isdigit(token[0])) {
            stack_.push(token[0] - '0');
        } else if (token.size() == 2 && token[0] == '-' && isdigit(token[1])) {
            stack_.push((token[1] - '0') * -1);
        } else if (token.size() == 1 && (token[0] == '-' || token[0] == '*' ||
                token[0] == '+' || token[0] == '/')) {
            if (stack_.size() < 2) throw std::runtime_error("Error: not enough operands.");
            int left = stack_.top();
            stack_.pop();
            int right = stack_.top();
            stack_.pop();
            int res;
            switch(token[0]) {
                case '/':
                    if (left == 0) throw std::runtime_error("Error: division by zero.");
                    res = right / left;
                    break;
                case '+':
                    res = left + right;
                    break;
                case '*':
                    res = left * right;
                    break;
                case '-':
                    res = right - left;
                    break;
            }
            stack_.push(res);
        } else {
            throw std::runtime_error("Error: wrong input.");
        }
    }
    if (stack_.size() != 1) throw std::runtime_error("Error: invalid input.");
}

int RPN::getResult() const {
    return stack_.top();
}