// File name: expression_demo_live_complete.cpp
// Name: Tong Yi
// Class demo: tokenize -> toPostfix -> evalPostfix (complete version)
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
double evalPostfix(std::queue<std::string> postfix);
double evalInfix(std::queue<std::string> infix);

int main() {
  std::queue<std::string> infix = tokenize("12 + 3 * (1 - 2) / 4");
  print(infix);

  std::queue<std::string> postfix = toPostfix(infix);
  print(postfix);

  std::cout << evalPostfix(postfix) << '\n';

  // Two stacks: evaluate the infix tokens directly, no postfix needed.
  std::cout << evalInfix(infix) << '\n';
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
      ops.push(token);
    }
    else if (token == ")") {
      while (!ops.empty() && ops.top() != "(") {
        postfix.push(ops.top());
        ops.pop();
      }
      if (ops.empty()) {
        throw std::invalid_argument("unmatched )");
      }
      ops.pop();  // discard the matching (
    }
    else {
      throw std::invalid_argument("invalid token");
    }
  }

  // dump the rest of ops
  while (!ops.empty()) {
    if (ops.top() == "(") {
      throw std::invalid_argument("unmatched (");
    }
    postfix.push(ops.top());
    ops.pop();
  }

  return postfix;
}

double evalPostfix(std::queue<std::string> postfix) {
  std::stack<double> values;
  while (!postfix.empty()) {
    std::string token = postfix.front();
    postfix.pop();

    if (std::isdigit(token[0])) {
      values.push(std::stod(token));
    }
    else {
      if (values.size() < 2) {
        throw std::invalid_argument("not enough operands");
      }
      double right = values.top();  // the right operand comes off first
      values.pop();
      double left = values.top();
      values.pop();

      if (token == "+") {
        values.push(left + right);
      }
      else if (token == "-") {
        values.push(left - right);
      }
      else if (token == "*") {
        values.push(left * right);
      }
      else if (token == "/") {
        if (right == 0.0) {
          throw std::invalid_argument("division by zero");
        }
        values.push(left / right);
      }
      else {
        throw std::invalid_argument("invalid operator");
      }
    }
  }

  if (values.size() != 1) {
    throw std::invalid_argument("invalid expression");
  }
  return values.top();
}

// Pop one operator and two values, then push the result.
// Precondition: ops is not empty (every call below checks this first).
void applyTop(std::stack<double>& values, std::stack<std::string>& ops) {
  std::string op = ops.top();
  ops.pop();
  if (values.size() < 2) {
    throw std::invalid_argument("not enough operands");
  }
  double right = values.top();  // the right operand comes off first
  values.pop();
  double left = values.top();
  values.pop();

  if (op == "+") {
    values.push(left + right);
  }
  else if (op == "-") {
    values.push(left - right);
  }
  else if (op == "*") {
    values.push(left * right);
  }
  else if (op == "/") {
    if (right == 0.0) {
      throw std::invalid_argument("division by zero");
    }
    values.push(left / right);
  }
  else {
    throw std::invalid_argument("invalid operator");
  }
}

// Evaluate infix directly with two stacks: one for values, one for
// operators. An operator waits on the operator stack until an operator of
// lower precedence (or ")") arrives. Same rules as toPostfix, but instead of
// sending an operator to the output we apply it right away.
double evalInfix(std::queue<std::string> infix) {
  std::stack<double> values;
  std::stack<std::string> ops;
  while (!infix.empty()) {
    std::string token = infix.front();
    infix.pop();

    if (std::isdigit(token[0])) {
      values.push(std::stod(token));
    }
    else if (token == "+" || token == "-" || token == "*" || token == "/") {
      while (!ops.empty() && prec(ops.top()) >= prec(token)) {
        applyTop(values, ops);
      }
      ops.push(token);
    }
    else if (token == "(") {
      ops.push(token);
    }
    else if (token == ")") {
      while (!ops.empty() && ops.top() != "(") {
        applyTop(values, ops);
      }
      if (ops.empty()) {
        throw std::invalid_argument("unmatched )");
      }
      ops.pop();  // discard the matching (
    }
    else {
      throw std::invalid_argument("invalid token");
    }
  }

  while (!ops.empty()) {
    if (ops.top() == "(") {
      throw std::invalid_argument("unmatched (");
    }
    applyTop(values, ops);
  }

  if (values.size() != 1) {
    throw std::invalid_argument("invalid expression");
  }
  return values.top();
}
