//File name: evaluate_postfix_string.cpp
#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>
#include <cctype>

// Evaluate postfix text using one operand stack.
// Supports nonnegative integer literals and binary +, -, *, /.
// Intermediate results may be negative or fractional.
double postfixProcess(const std::string& s);

int main() {
  std::cout << postfixProcess("7 2 /") << '\n'; // 3.5
  std::cout << postfixProcess("20 6 2 - /") << '\n'; // 5
  return 0;
}

double postfixProcess(const std::string& s) {
  std::stack<double> operands;
  std::size_t i = 0;
  while (i < s.length()) {
    if (std::isdigit(static_cast<unsigned char>(s[i]))) {
      double num = 0;
      while (i < s.length() && std::isdigit(static_cast<unsigned char>(s[i]))) {
        num = num * 10 + (s[i] - '0');
        i++;
      }
      operands.push(num);
      continue; // i already equal to s.length() or points past the number
    }
    else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
      if (operands.size() < 2) {
        throw std::runtime_error(std::string("need two operands for operator ") + s[i]);
      }

      double num2 = operands.top();
      operands.pop();

      double num = operands.top();
      operands.pop();

      switch (s[i]) {
        case '+':
          operands.push(num + num2);
          break;
        case '-':
          operands.push(num - num2);
          break;
        case '*':
          operands.push(num * num2);
          break;
        case '/':
          if (num2 == 0) {
            throw std::runtime_error("division by zero");
          }
          operands.push(num / num2);
          break;
       }
    }
    else if (!std::isspace(static_cast<unsigned char>(s[i]))) {
      throw std::runtime_error(
        std::string("invalid character: ") + s[i]);
    }
    i++;
  }

  if (operands.empty()) {
    throw std::runtime_error("missing operand");
  }

  double value = operands.top();
  operands.pop();

  if (!operands.empty()) {
    throw std::runtime_error(std::string("extra operands: ") + s);
  }
  return value;
}
