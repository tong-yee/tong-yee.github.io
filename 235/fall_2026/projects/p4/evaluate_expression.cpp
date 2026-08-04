// File name: evaluate_expression.cpp
// Name:
// Email:
//
// P4 — Expression Evaluator
//
// Implement the four functions marked TO IMPLEMENT below.
// The main() test harness is already written; do not modify it.
//
// Compile:
//   g++ -std=c++17 -Wall -Wextra -o evaluator evaluate_expression.cpp
//
// Run tests:
//   ./evaluator A   — Task A: precedence()
//   ./evaluator B   — Task B: binaryOperation()
//   ./evaluator C   — Task C: processString() basic  (numbers + operators, no parens)
//   ./evaluator D   — Task D: processString() full + calculate()

#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <cctype>
#include <stdexcept>

// ── PreviousToken ─────────────────────────────────────────────────────────────
// Tracks the kind of token most recently parsed.
// processString() uses this to decide whether '-' is unary negation or
// binary subtraction, and to detect malformed expressions.
enum class PreviousToken {
  START,        // beginning of the expression
  NUMBER,       // just processed a number (operand)
  UNARY_MINUS,  // just processed unary '-', waiting for a number
  OPERATOR,     // just processed a binary operator
  OPEN_PAREN,   // just processed '('
  CLOSE_PAREN   // just processed ')'
};

// ── Function declarations ─────────────────────────────────────────────────────
int    precedence(char ch);
void   binaryOperation(std::stack<double>& operands, std::stack<char>& operators);
void   processString(const std::string& str,
                     std::stack<double>& operands,
                     std::stack<char>&   operators);
double calculate(const std::string& expr);

// ── Helpers for main() ────────────────────────────────────────────────────────
static void print_result(const std::string& label, int passed, int total) {
  if (passed == total)
    std::cout << "Task " << label << ": all " << total << " tests passed.\n";
  else
    std::cout << "Task " << label << ": " << passed << "/" << total
              << " tests passed.\n";
}

// ── main() — do not modify ────────────────────────────────────────────────────
int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <A|B|C|D>\n";
    return 1;
  }
  const std::string opt(argv[1]);
  const double DELTA = 1e-4;

  // ── Task A: precedence() ───────────────────────────────────────────────────
  // Tests that each operator returns its correct precedence level.
  if (opt == "A") {
    int pass = 0, total = 7;

    auto chk = [&](char c, int expected) {
      try {
        int got = precedence(c);
        if (got == expected) { pass++; return; }
        std::cout << "FAIL: precedence('" << c << "') expected "
                  << expected << ", got " << got << "\n";
      } catch (...) {
        std::cout << "FAIL: precedence('" << c << "') threw unexpectedly\n";
      }
    };

    chk('+', 1);
    chk('-', 1);
    chk('*', 2);
    chk('/', 2);
    chk('(', 0);
    chk(')', 0);

    // unknown character must throw
    try {
      precedence('?');
      std::cout << "FAIL: precedence('?') should throw but returned a value\n";
    } catch (const std::runtime_error&) { pass++; }

    print_result("A", pass, total);
  }

  // ── Task B: binaryOperation() ─────────────────────────────────────────────
  // Tests stack pop/push behavior and operand order.
  else if (opt == "B") {
    int pass = 0, total = 8;

    // Push a op b, call binaryOperation, check result.
    // a is the deeper operand (pushed first), b is on top.
    auto chk = [&](double a, char op, double b, double expected,
                   const char* label) {
      std::stack<double> nums;
      std::stack<char>   ops;
      nums.push(a); nums.push(b);
      ops.push(op);
      try {
        binaryOperation(nums, ops);
        if (nums.size() == 1 && std::fabs(nums.top() - expected) <= DELTA) {
          pass++;
        } else {
          std::cout << "FAIL: " << label << " expected " << expected;
          if (nums.size() == 1) std::cout << ", got " << nums.top();
          else std::cout << " (wrong stack size: " << nums.size() << ")";
          std::cout << "\n";
        }
      } catch (const std::runtime_error& e) {
        std::cout << "FAIL: " << label << " threw unexpectedly: "
                  << e.what() << "\n";
      }
    };

    chk(3, '+', 2, 5,    "3 + 2");
    chk(7, '-', 3, 4,    "7 - 3");
    chk(4, '*', 5, 20,   "4 * 5");
    chk(9, '/', 4, 2.25, "9 / 4");
    chk(5, '-', 3, 2,    "5 - 3 (order check: should be 2, not -2)");

    // empty operator stack must throw
    try {
      std::stack<double> n; n.push(5); n.push(3);
      std::stack<char>   o;             // deliberately empty
      binaryOperation(n, o);
      std::cout << "FAIL: binaryOperation with empty operator stack "
                   "should throw but didn't\n";
    } catch (const std::runtime_error&) { pass++; }

    // divide by zero must throw
    try {
      std::stack<double> n; n.push(1); n.push(0);
      std::stack<char>   o; o.push('/');
      binaryOperation(n, o);
      std::cout << "FAIL: 1 / 0 should throw but returned a value\n";
    } catch (const std::runtime_error&) { pass++; }

    // too few operands must throw
    try {
      std::stack<double> n; n.push(5);   // only one operand
      std::stack<char>   o; o.push('+');
      binaryOperation(n, o);
      std::cout << "FAIL: binaryOperation with 1 operand should throw but didn't\n";
    } catch (const std::runtime_error&) { pass++; }

    print_result("B", pass, total);
  }

  // ── Task C: processString() basic — no parentheses, no unary minus ─────────
  // Implement the digit-extraction and binary-operator branches of
  // processString(), plus Steps 1, 2, and 3 of calculate(), to pass these tests.
  else if (opt == "C") {
    int pass = 0, total = 10;

    auto chk = [&](const char* expr, double expected) {
      try {
        double got = calculate(expr);
        if (std::fabs(got - expected) <= DELTA) { pass++; return; }
        std::cout << "FAIL: calculate(\"" << expr << "\") expected "
                  << expected << ", got " << got << "\n";
      } catch (const std::runtime_error& e) {
        std::cout << "FAIL: calculate(\"" << expr << "\") threw unexpectedly: "
                  << e.what() << "\n";
      }
    };

    chk("1",          1);
    chk("1+2",        3);
    chk("2-1",        1);
    chk("2*3",        6);
    chk("1/2",        0.5);
    chk("1+2*3",      7);        // precedence: * before +
    chk("2+3*4-5",    9);        // 2 + 12 - 5
    chk("1 + 2 * 3",  7);        // spaces are skipped
    chk("42",         42);
    chk("12+34*56",   1916);

    print_result("C", pass, total);
  }

  // ── Task D: full calculate() — parentheses, unary minus, error handling ────
  // Complete processString() (parentheses + unary minus + all error cases)
  // and add the unmatched '(' guard to calculate().
  else if (opt == "D") {
    int vpass = 0;

    auto chk = [&](const char* expr, double expected) {
      try {
        double got = calculate(expr);
        if (std::fabs(got - expected) <= DELTA) { vpass++; return; }
        std::cout << "FAIL: calculate(\"" << expr << "\") expected "
                  << expected << ", got " << got << "\n";
      } catch (const std::runtime_error& e) {
        std::cout << "FAIL: calculate(\"" << expr << "\") threw unexpectedly: "
                  << e.what() << "\n";
      }
    };

    // Valid — parentheses (6)
    chk("2*(1+3)",                   8);
    chk("(1+3)*2",                   8);
    chk("((4+3)/(3*2))",       1.16667);
    chk("(1+2*3)",                   7);
    chk("7+((4+3)-(3*2))",           8);
    chk("((3))",                     3);   // nested parens around single number

    // Valid — unary minus (12)
    // ┌─ SUBTLE DIFFERENCE ─────────────────────────────────────────────────┐
    // │  "- -3"   is an ERROR:  first '-' → UNARY_MINUS; second '-' arrives  │
    // │           while prev==UNARY_MINUS → consecutive unary → throw.        │
    // │  "3 - -5" is VALID:     first '-' is BINARY (prev==NUMBER) → OPERATOR;│
    // │           second '-' arrives while prev==OPERATOR → UNARY_MINUS;      │
    // │           '5' is negated to -5; result 3-(-5)=8.                      │
    // │  Rule: what matters is prev *before* the '-' arrives, not spacing.    │
    // └─────────────────────────────────────────────────────────────────────┘
    chk("-3",          -3);
    chk("-3-(-2)",     -1);
    chk("-3--5",        2);   // -3 - (-5) = 2
    chk("-1+3",         2);
    chk("3--2",         5);   // 3 - (-2) = 5
    chk("- 3",         -3);   // space between unary '-' and operand
    chk("3 - - 5",      8);   // binary '-', then unary '-'; 3-(-5)=8
    chk("3+-2",         1);   // binary '+', then unary '-'; 3+(-2)=1
    chk("(- 5)",       -5);   // unary '-' inside parens with space
    chk("3 + (-2)",     1);
    chk("3*-2",        -6);   // binary '*', then unary '-'
    chk("3/-2",       -1.5);  // binary '/', then unary '-'

    print_result("D valid", vpass, 18);

    // Error expressions — each must throw std::runtime_error (20 cases)
    int epass = 0, etotal = 20;

    auto chk_err = [&](const char* expr) {
      try {
        double result = calculate(expr);
        std::cout << "FAIL: calculate(\"" << expr
                  << "\") should throw but returned " << result << "\n";
      } catch (const std::runtime_error&) { epass++; }
    };

    chk_err("   ");      // whitespace-only
    chk_err("1+");       // trailing operator
    chk_err("((1+2)");   // unmatched '('
    chk_err("()");       // empty parentheses
    chk_err("*3");       // non-unary leading operator
    chk_err("-()");      // unary minus before '(' not supported
    chk_err("3 + -");    // dangling unary minus at end
    chk_err("-(3+4)");   // unary minus before '(' not supported
    chk_err("2(3+4)");   // missing operator before '('
    chk_err("(1+2)3");   // missing operator after ')'
    chk_err("(3)(4)");   // missing operator between ')' and '('
    chk_err("3 4");      // missing operator between two numbers
    chk_err("--3");      // consecutive unary minus
    chk_err("- -3");     // consecutive unary minus (with space)
    chk_err("3-");       // trailing operator (subtraction)
    chk_err("(");        // lone open paren
    chk_err(")");        // unmatched ')'
    chk_err("3/0");      // divide by zero
    chk_err("(( ))");    // parens with only whitespace inside
    chk_err("(3+)");     // missing operand before ')'

    print_result("D errors", epass, etotal);
  }

  else {
    std::cerr << "Unknown task: " << opt << "\n";
    return 1;
  }
  return 0;
}

// ════════════════════════════════════════════════════════════════════════════
//  IMPLEMENT THE FOUR FUNCTIONS BELOW
// ════════════════════════════════════════════════════════════════════════════

// ── Task A: precedence() ──────────────────────────────────────────────────────
// Return the precedence (priority) of operator ch:
//   +  and  -   →  1
//   *  and  /   →  2
//   (  and  )   →  0
//   '(' acts as a barrier on the operator stack;
//   ')' is handled immediately when encountered.
// Throw std::runtime_error for any other character.
//
// Why '(' returns 0: during the Shunting-Yard scan, we pop operators whose
// precedence is >= the incoming operator's precedence.  Giving '(' a value of
// 0 means no ordinary operator ever pops it — it acts as a barrier until a
// matching ')' is found.
int precedence(char ch) {
  // TODO
  return -1;  // placeholder — remove this line when you implement
}

// ── Task B: binaryOperation() ────────────────────────────────────────────────
// Apply the top operator to the top two operands and push the result.
//
// Stack state before the call (example: "5 - 3"):
//   operands:  [5, 3]   ← 3 is on top
//   operators: ['-']
//
// Steps:
//   1. Pop the top of operands → num2   (3)
//   2. Pop the next operand    → num1   (5)
//   3. Pop the top of operators → op   ('-')
//   4. Compute num1 op num2            (5 - 3 = 2)
//   5. Push the result                 (operands: [2])
//
// Throw std::runtime_error if:
//   - fewer than 2 operands are available
//   - the operator stack is empty
//   - op is '/' and num2 == 0 (divide by zero)
//   - op is not one of +, -, *, / (unrecognized operator)
void binaryOperation(std::stack<double>& operands, std::stack<char>& operators) {
  // TODO
}

// ── Tasks C & D: processString() ─────────────────────────────────────────────
// Scan str character by character, building the operands and operators stacks.
// PreviousToken prev records what was just seen, guiding each decision.
//
// ── Task C: handle digits and binary operators ───────────────────────────────
//
// Digits (std::isdigit):
//   Read a complete integer (advance i while the next char is also a digit).
//   After the loop, backtrack: i-- so the outer i++ lands correctly.
//   Push the value onto operands.  Set prev = NUMBER.
//   Error if prev == NUMBER or CLOSE_PAREN (a new number cannot immediately follow a number or ')').
//
// Operators (+, -, *, /):
//   Binary context (prev == NUMBER or CLOSE_PAREN):
//     Shunting-Yard: while the operator stack is not empty and
//       precedence(operators.top()) >= precedence(ch), call binaryOperation().
//     Then push ch onto operators.  Set prev = OPERATOR.
//   [Unary context handled in Task D]
//
// Spaces: skip silently (do NOT write a second i++).
// Unknown character: throw std::runtime_error.
//
// ── Task D: add parentheses, unary minus, and error handling ─────────────────
//
// Unary minus (prev == START, OPERATOR, or OPEN_PAREN, and ch == '-'):
//   Do NOT push '-' onto operators.  Set prev = UNARY_MINUS.
//   When the next number is parsed, negate it before pushing.
//   Any other operator (+, *, /) in unary position is an error.
//   Consecutive unary operators (prev == UNARY_MINUS) are an error.
//
// ┌─ SUBTLE DIFFERENCE ───────────────────────────────────────────────────────┐
// │  "- -3"   ERROR:  first '-' → UNARY_MINUS; second '-' sees                │
// │           prev==UNARY_MINUS → consecutive unary → throw.                  │
// │  "3 - -5" VALID:  first '-' is binary (prev==NUMBER) → OPERATOR;          │
// │           second '-' sees prev==OPERATOR → UNARY_MINUS; '5' negated.      │
// │  Spaces do not matter — only the prev state before '-' arrives counts.    │
// └───────────────────────────────────────────────────────────────────────────┘
//
// Open parenthesis '(':
//   Push '(' onto operators.  Set prev = OPEN_PAREN.
//   Error if prev == NUMBER or CLOSE_PAREN (write: "Need operator before (").
//   Error if prev == UNARY_MINUS (write: "Unary minus before '(' is not supported").
//
// Close parenthesis ')':
//   Pop and evaluate operators until '(' is found; discard the '('.
//   Set prev = CLOSE_PAREN.
//   Error if an operand is still expected (prev == START, UNARY_MINUS,
//     OPERATOR, or OPEN_PAREN): write "Need operand before )".
//   Error if no matching '(' is found: write "Missing (".
void processString(const std::string& str,
                   std::stack<double>& operands,
                   std::stack<char>&   operators) {
  int i   = 0;
  int len = static_cast<int>(str.size());
  PreviousToken prev = PreviousToken::START;

  while (i < len) {
    char ch = str[i];

    if (std::isdigit(static_cast<unsigned char>(ch))) {
      // Task C: extract multi-digit number, push onto operands
      // TODO

    } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      // Task C: implement the binary-operator case
      //   (prev == NUMBER or CLOSE_PAREN).
      // Task D: your Task C code becomes one branch of a larger if/else;
      //   add unary-context handling and error checks in the other branches.
      // TODO

    } else if (ch == '(') {
      // Task D: push onto operators; handle error cases
      // TODO

    } else if (ch == ')') {
      // Task D: drain until '('; handle missing-'(' error
      // TODO

    } else if (ch == ' ') {
      ;  // skip — do NOT write i++ here; the outer i++ already advances

    } else {
      throw std::runtime_error(std::string("wrong symbol: ") + ch);
    }

    i++;
  }
}

// ── Task C & D: calculate() ──────────────────────────────────────────────────
// Evaluate expr and return the numeric result.
//
// *** Task C tests call calculate() directly.
//     Complete all three steps below as part of Task C. ***
//
// Step 1 (Task C) — parse the expression:
//   Call processString(expr, operands, operators).
//
// Step 2 (Task C) — basic drain loop:
//   while (!operators.empty()) { binaryOperation(operands, operators); }
//
//   Task D upgrade: inside the loop, guard against an unmatched '(' BEFORE
//   calling binaryOperation:
//     if (operators.top() == '(') throw std::runtime_error("Unmatched (");
//
// Step 3 (Task C) — return the result:
//   if (operands.size() != 1) throw std::runtime_error("Invalid expression");
//   return operands.top();
//   Remove the placeholder return 0.0 below when you reach this step.
double calculate(const std::string& expr) {
  std::stack<double> operands;
  std::stack<char>   operators;

  // Step 1 (Task C): call processString()
  // TODO

  // Step 2 (Task C): drain loop
  // TODO: while (!operators.empty()) { binaryOperation(operands, operators); }
  // Step 2 (Task D): add '(' guard inside the loop before calling binaryOperation

  // Step 3 (Task C & D): verify and return
  // TODO: if (operands.size() != 1) throw std::runtime_error("Invalid expression");
  // TODO: return operands.top();
  return 0.0;  // placeholder — remove this line when you implement Step 3
}
