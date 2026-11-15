// File name: expression_demo_live_complete.cpp
// Name: Tong Yi
// Class demo: tokenize -> toPostfix -> evalPostfix (complete version, without evalInfix)
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

int main() {
  std::queue<std::string> infix = tokenize("12 + 3 * (1 - 2) / 4");
  print(infix);

  std::queue<std::string> postfix = toPostfix(infix);
  print(postfix);

  std::cout << evalPostfix(postfix) << '\n';

  // Project 4 idea: evaluate the infix tokens directly with two stacks
  // (see the key steps below). Write evalInfix yourself.
  return 0;
}

std::queue<std::string> tokenize(const std::string& expr) {
  std::queue<std::string> que;
  int len = static_cast<int>(expr.length());
  int i = 0;
  while (i < len) {
    char ch = expr[i];

    if (std::isdigit(static_cast<unsigned char>(ch))) {
      std::string numStr;
      while (i < len && std::isdigit(static_cast<unsigned char>(expr[i]))) {
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
    else if (std::isspace(static_cast<unsigned char>(ch))) {
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

    if (std::isdigit(static_cast<unsigned char>(token[0]))) {
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

    if (std::isdigit(static_cast<unsigned char>(token[0]))) {
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

// Key steps of evalInfix (two stacks, no postfix queue). Code left for you.
//   values: stack of numbers        ops: stack of operators
//   For each token:
//     1. number      -> convert it and push it on values.
//     2. operator    -> while ops is not empty and prec(ops.top()) >= prec(token):
//                         apply the top operator (pop two values, push the result).
//                       then push the token on ops.
//     3. "("         -> push it on ops; apply nothing.
//     4. ")"         -> apply operators until "(" is on top of ops;
//                       discard the "("; if ops runs out first, throw.
//     5. anything else -> throw an invalid-token error.
//   After the last token:
//     6. apply every remaining operator; if one of them is "(", throw.
//   Applying an operator: pop the RIGHT operand first, then the left;
//   throw on division by zero; push the result.
//   When done, values holds exactly one number: the answer.
