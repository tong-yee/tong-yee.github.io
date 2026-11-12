// File name: expression_demo_use_queue.cpp
//
// Live demo for Day 19: tokenize -> toPostfix -> evalPostfix.
//
// Assumes syntactically valid infix expressions containing nonnegative
// integer literals, binary operators +, -, *, /, and balanced parentheses.
// Unary minus and decimal literals are not supported.
// Intermediate evaluation results may be fractional.
// Some invalid inputs are detected, but this is not a complete syntax
// validator.
#include <cctype>
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>  // std::invalid_argument
#include <string>

// Convert a string to a queue of tokens: an integer, +, -, *, /, ( or ).
std::queue<std::string> tokenize(const std::string& s);
// Queue parameters are passed by value because these functions
// consume their local copies using front() and pop().
std::queue<std::string> toPostfix(std::queue<std::string> infix);
int prec(const std::string& op);
double evalPostfix(std::queue<std::string> postfix);

// Pass by value so that popping elements does not modify
// the caller's queue.
void print(std::queue<std::string> que);

int main() {
  std::string expr("12 + 3 * (1 - 2) / 4");
  std::queue<std::string> tokens = tokenize(expr);
  std::cout << "tokens in expression: " << expr << '\n';
  print(tokens);

  std::queue<std::string> postfix = toPostfix(tokens);
  std::cout << "tokens in postfix expression:\n";
  print(postfix);

  std::cout << evalPostfix(postfix) << '\n';
  return 0;
}

std::queue<std::string> tokenize(const std::string& s) {
  std::queue<std::string> tokens;

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
      tokens.push(numStr);
    }
    else if (s[i] == '(' || s[i] == ')' ||
             s[i] == '+' || s[i] == '-' ||
             s[i] == '*' || s[i] == '/') {
      tokens.push(std::string(1, s[i]));
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

void print(std::queue<std::string> que) {
  while (!que.empty()) {
    std::cout << que.front() << ' ';
    que.pop();
  }
  std::cout << '\n';
}

// shunting yard algorithm
std::queue<std::string> toPostfix(std::queue<std::string> infix) {
  std::queue<std::string> postfix;
  std::stack<std::string> operators;  // waiting to be added to postfix
  while (!infix.empty()) {
    std::string token = infix.front();
    infix.pop();
    if (std::isdigit(static_cast<unsigned char>(token[0]))) {
      postfix.push(token);
    }
    else if (token == "+" || token == "-" ||
             token == "*" || token == "/") {
      // Pop operators of higher or equal precedence.
      // Stop at ( or an operator of lower precedence.
      while (!operators.empty() && prec(operators.top()) >= prec(token)) {
        postfix.push(operators.top());
        operators.pop();
      }

      // After the loop, either:
      // 1. operators.empty(), or
      // 2. !operators.empty() &&
      //    prec(operators.top()) < prec(token).
      // In case 2, the top is '(' or an operator of lower precedence.
      operators.push(token);
    }
    else if (token == "(") {
      operators.push(token);
    }
    else if (token == ")") {
      while (!operators.empty() && operators.top() != "(") {
        postfix.push(operators.top());
        operators.pop();
      }

      // After the loop, if the operator stack is not empty,
      // its top element must be '('.
      if (operators.empty()) {
        throw std::invalid_argument("Unmatched closing parenthesis");
      }
      operators.pop();  // pop the matched '('
    }
    else {
      throw std::invalid_argument("Invalid token in infix expression");
    }
  }

  while (!operators.empty()) {
    // An unmatched ( must not be added to the postfix expression.
    if (operators.top() == "(") {
      throw std::invalid_argument("Unmatched opening parenthesis");
    }
    postfix.push(operators.top());
    operators.pop();
  }

  return postfix;
}

int prec(const std::string& op) {
  if (op == "(") {
    return 0;
  }
  else if (op == "+" || op == "-") {
    return 1;
  }
  else if (op == "*" || op == "/") {
    return 2;
  }

  return -1;
}

double evalPostfix(std::queue<std::string> postfix) {
  std::stack<double> operands;
  while (!postfix.empty()) {
    std::string token = postfix.front();
    postfix.pop();
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
