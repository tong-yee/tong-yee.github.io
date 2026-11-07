// class18_expression_evaluator.cpp -- companion listing for Class 18 (CSCI 235)
//
// Complete, runnable version of the code shown on the slides:
//   tokenize -> toPostfix (infix to postfix) -> evalPostfix.
//
// VALID-INPUT VERSION (values are double, so "/" is real division: 7 / 2 is 3.5). evalPostfix assumes a valid postfix sequence; the
// converter assumes the input is a valid expression made of
// nonnegative integer literals, binary + - * /, and balanced parentheses.
// Unary minus and decimal literals are NOT supported. It does not check for:
//   * an unmatched ")" (ops.top() on an empty stack is undefined behavior)
//   * an unmatched "(" left at the end (it would be sent to the output)
//   * too few operands for an operator, or leftover values after evaluating
//   * invalid characters (tokenize accepts any non-digit, non-space character)
//   * infix operand/operator order: a malformed expression such as "1 2 +" is
//     not rejected (it converts and evaluates as if it were valid)
//   * division by zero, or an oversized literal (std::stod throws)
// Project 4 code must add these checks.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o expr class18_expression_evaluator.cpp

#include <cctype>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

bool isOp(const std::string& t) {
    return t == "+" || t == "-" || t == "*" || t == "/";
}

std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> tokens;
    std::size_t i = 0;
    while (i < text.size()) {
        if (std::isspace(static_cast<unsigned char>(text[i]))) { ++i; }
        else if (std::isdigit(static_cast<unsigned char>(text[i]))) {
            std::string num;
            while (i < text.size() &&
                   std::isdigit(static_cast<unsigned char>(text[i]))) {
                num += text[i++];
            }
            tokens.push_back(num);                      // a whole number, e.g. "12"
        } else {
            tokens.push_back(std::string(1, text[i++])); // assumed to be one of + - * / ( )
        }
    }
    return tokens;
}
// tokenize("12+3*(4-1)")  gives  {"12", "+", "3", "*", "(", "4", "-", "1", ")"}

double evalPostfix(std::queue<std::string> postfix) {
    std::stack<double> values;
    while (!postfix.empty()) {
        std::string t = postfix.front();
        postfix.pop();
        if (isOp(t)) {
            double b = values.top(); values.pop();   // right operand first
            double a = values.top(); values.pop();   // then the left operand
            if (t == "+")      { values.push(a + b); }
            else if (t == "-") { values.push(a - b); }
            else if (t == "*") { values.push(a * b); }
            else               { values.push(a / b); }
        } else {
            values.push(std::stod(t));               // a number: push it
        }
    }
    return values.top();                             // the one value left
}

int prec(const std::string& op) {
    if (op == "*" || op == "/") { return 2; }
    return 1;                                            // "+" and "-"
}

std::queue<std::string> toPostfix(const std::vector<std::string>& tokens) {
    std::queue<std::string> output;
    std::stack<std::string> ops;
    for (const std::string& t : tokens) {
        if (isOp(t)) {
            while (!ops.empty() && isOp(ops.top()) && prec(ops.top()) >= prec(t)) {
                output.push(ops.top()); ops.pop();       // stronger or equal leaves
            }
            ops.push(t);
        } else if (t == "(") {
            ops.push(t);
        } else if (t == ")") {
            while (ops.top() != "(") { output.push(ops.top()); ops.pop(); }
            ops.pop();                                   // discard the "("
        } else {
            output.push(t);                              // a number goes straight out
        }
    }
    while (!ops.empty()) { output.push(ops.top()); ops.pop(); }
    return output;
}

// ── Small test driver ─────────────────────────────────────────────────────
static std::string join(std::queue<std::string> q) {
    std::string s;
    while (!q.empty()) {
        s += q.front();
        q.pop();
        if (!q.empty()) { s += " "; }
    }
    return s;
}

int main() {
    struct Case { const char* infix; const char* postfix; double value; };
    std::vector<Case> cases = {
        {"3 + 4 * 2",             "3 4 2 * +",             11},
        {"(3 + 4) * 2",           "3 4 + 2 *",             14},
        {"8 - 3 - 2",             "8 3 - 2 -",             3},
        {"5 + (1 + 2) * 4 - 3",   "5 1 2 + 4 * + 3 -",     14},
        {"12 / (2 + 1) - 1",      "12 2 1 + / 1 -",        3},
        {"7 / 2",                 "7 2 /",                 3.5},
        {"(2 + 3) * (4 - 1)",     "2 3 + 4 1 - *",         15},
    };
    int pass = 0;
    for (const Case& c : cases) {
        std::queue<std::string> post = toPostfix(tokenize(c.infix));
        std::string got = join(post);
        double value = evalPostfix(post);
        bool ok = (got == c.postfix && std::fabs(value - c.value) < 1e-9);
        if (ok) { ++pass; }
        std::cout << (ok ? "ok   " : "FAIL ") << c.infix << "  ->  " << got
                  << "  =  " << value << "\n";
    }
    std::cout << pass << "/" << cases.size() << " tests passed.\n";
    return 0;
}
