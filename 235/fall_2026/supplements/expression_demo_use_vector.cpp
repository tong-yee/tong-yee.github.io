// File name: expression_demo_use_vector.cpp

// Assumes syntactically valid infix expressions containing nonnegative
// integer literals, binary operators +, -, *, /, and balanced parentheses.
// Unary minus and decimal literals are not supported.
// Intermediate evaluation results may be fractional.
// Some invalid inputs are detected, but this is not a complete syntax
// validator.
#include <cctype>
#include <iostream>
#include <stack>
#include <stdexcept>  // std::invalid_argument
#include <string>
#include <vector>

// Convert a string to a vector of tokens: an integer, +, -, *, /, ( or ).
std::vector<std::string> tokenize(const std::string& s);
std::vector<std::string> toPostfix(const std::vector<std::string>& infix);
int prec(char op);
double evalPostfix(const std::vector<std::string>& postfix);

void print(const std::vector<std::string>& v);

int main() {
  std::string expr("12 + 3 * (1 - 2) / 4");
  std::vector<std::string> tokens = tokenize(expr);
  std::cout << "tokens in expression: " << expr << '\n';
  print(tokens);

  std::vector<std::string> postfix = toPostfix(tokens);
  std::cout << "tokens in postfix expression:\n";
  print(postfix);

  std::cout << evalPostfix(postfix) << '\n';
  return 0;
}

std::vector<std::string> tokenize(const std::string& s) {
  std::vector<std::string> tokens;

  int len = static_cast<int>(s.length());
  int i = 0;
  while (i < len) {
    if (s[i] == ' ') {
      i++;
    }
    else if (std::isdigit(static_cast<unsigned char>(s[i]))) {
      std::string numStr;
      while (i < len && std::isdigit(static_cast<unsigned char>(s[i]))) {
        numStr += s[i];
        i++;
      }
      tokens.push_back(numStr);
    }
    else if (s[i] == '(' || s[i] == ')' ||
             s[i] == '+' || s[i] == '-' ||
             s[i] == '*' || s[i] == '/') {
      tokens.push_back(std::string(1, s[i]));
      i++;
    }
    else {
      // Without this branch, an unsupported character would cause
      // an infinite loop because i would not advance.
      throw std::invalid_argument("Invalid character in infix expression");
    }
  }

  return tokens;
}

void print(const std::vector<std::string>& v) {
  for (const auto& s : v) {
    std::cout << s << ' ';
  }
  std::cout << '\n';
}

// shunting yard algorithm
std::vector<std::string> toPostfix(const std::vector<std::string>& infix) {
  std::vector<std::string> postfix;
  std::stack<char> operators;  // operators waiting to be added to postfix
  for (const auto& token : infix) {
    if (std::isdigit(static_cast<unsigned char>(token[0]))) {
      postfix.push_back(token);
    }
    else if (token[0] == '+' || token[0] == '-' ||
             token[0] == '*' || token[0] == '/') {
      // Pop operators of higher or equal precedence.
      // Stop at '(' or an operator of lower precedence.
      while (!operators.empty() && prec(operators.top()) >= prec(token[0])) {
        postfix.push_back(std::string(1, operators.top()));
        operators.pop();
      }

      // After the loop, either:
      // 1. operators.empty(), or
      // 2. !operators.empty() &&
      //    prec(operators.top()) < prec(token[0]).
      // In case 2, the top is '(' or an operator of lower precedence.
      operators.push(token[0]);
    }
    else if (token[0] == '(') {
      operators.push(token[0]);
    }
    else if (token[0] == ')') {
      while (!operators.empty() && operators.top() != '(') {
        postfix.push_back(std::string(1, operators.top()));
        operators.pop();
      }

      // After the loop, if the operator stack is not empty,
      // its top element must be '('.
      if (operators.empty()) {
        throw std::invalid_argument("Unmatched closing parenthesis");
      }
      operators.pop();  // pop the matched '('
    }
  }

  while (!operators.empty()) {
    // An unmatched '(' must not be added to the postfix expression.
    if (operators.top() == '(') {
      throw std::invalid_argument("Unmatched opening parenthesis");
    }
    postfix.push_back(std::string(1, operators.top()));
    operators.pop();
  }

  return postfix;
}

int prec(char op) {
  if (op == '(') {
    return 0;
  }
  else if (op == '+' || op == '-') {
    return 1;
  }
  else if (op == '*' || op == '/') {
    return 2;
  }

  return -1;
}

double evalPostfix(const std::vector<std::string>& postfix) {
  std::stack<double> operands;
  for (const auto& token : postfix) {
    char ch = token[0];
    if (std::isdigit(static_cast<unsigned char>(ch))) {
      operands.push(std::stod(token));
    }
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      if (operands.size() < 2) {
        throw std::invalid_argument("need at least two operands");
      }

      double right = operands.top();
      operands.pop();
      double left = operands.top();
      operands.pop();
      switch (ch) {
        case '+': operands.push(left + right);
                  break;
        case '-': operands.push(left - right);
                  break;
        case '*': operands.push(left * right);
                  break;
        case '/': if (right == 0.0) {
                    throw std::invalid_argument("division by zero");
                  }
                  operands.push(left / right);
                  break;
      }
    }
    else {
      throw std::invalid_argument("Invalid token in postfix expression");
    }
  }

  // A valid postfix expression leaves exactly one value on the stack.
  if (operands.size() != 1) {
    throw std::invalid_argument("invalid expression");
  }

  return operands.top();
}
