// File name: expression_demo_live.cpp
// Name: Tong Yi
// Class demo: tokenize -> toPostfix -> evalPostfix (partial version)
//
// Thursday: finish the TODOs in toPostfix, write evalPostfix, then evalInfix.
#include <cctype>
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>  // std::invalid_argument
#include <string>

std::queue<std::string> tokenize(const std::string& expr);
void print(std::queue<std::string> que);
std::queue<std::string> toPostfix(std::queue<std::string> infix);
int prec(const std::string& op);

int main() {
  std::queue<std::string> infix = tokenize("12 + 4");
  print(infix);

  std::queue<std::string> postfix = toPostfix(infix);
  print(postfix);
  return 0;
}

std::queue<std::string> tokenize(const std::string& expr) {
  std::queue<std::string> que;
  int len = static_cast<int>(expr.length());
  int i = 0;
  while (i < len) {
    char ch = expr[i];

    if (std::isdigit(ch)) {
      std::string numStr;
      while (i < len && std::isdigit(expr[i])) {
        numStr += expr[i];
        i++;
      }
      que.push(numStr);
    }
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
             ch == '(' || ch == ')') {
      que.push(std::string(1, ch));
      i++;
    }
    else if (std::isspace(ch)) {
      i++;
    }
    else {
      throw std::invalid_argument("invalid character in infix expression");
    }
  }

  return que;
}

void print(std::queue<std::string> que) {
  while (!que.empty()) {
    std::cout << "\"" << que.front() << "\"" << " ";
    que.pop();
  }
  std::cout << '\n';
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
  else {
    throw std::invalid_argument("invalid operator");
  }
}

std::queue<std::string> toPostfix(std::queue<std::string> infix) {
  std::queue<std::string> postfix;
  std::stack<std::string> ops;  // operators waiting to be added to postfix
  while (!infix.empty()) {
    std::string token = infix.front();
    infix.pop();

    if (std::isdigit(token[0])) {
      postfix.push(token);
    }
    else if (token == "+" || token == "-" || token == "*" || token == "/") {
      while (!ops.empty() && prec(ops.top()) >= prec(token)) {
        postfix.push(ops.top());
        ops.pop();
      }
      ops.push(token);
    }
    else if (token == "(") {
      // TODO 1
    }
    else if (token == ")") {
      // TODO 2
    }
    else {
      // TODO 3: what should happen for any other token?
    }
  }

  // TODO 4: dump the rest of ops

  return postfix;
}

// TODO 5: declare and write
//   double evalPostfix(std::queue<std::string> postfix);
// and call it from main.

// TODO 6: evaluate the infix tokens DIRECTLY, with two stacks (one for
// values, one for operators), and no postfix queue. Declare and write
//   double evalInfix(std::queue<std::string> infix);
// and call it from main.
