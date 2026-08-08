// File name: make24.cpp  (rename this file to make24.cpp before submitting)
// Name:
// Email:
//
// P3 — Make 24, Task B: Single-Expression Solver
//
// Implement the three functions marked TODO below: both make24() overloads
// and arithmetic(). The main() test harness is already written; do not
// modify it.
//
// Task B returns an actual expression string instead of just true/false.
// The autograder does NOT compare your string against one fixed reference
// answer -- it independently checks that your expression (1) evaluates to
// 24 and (2) uses exactly the given operands. Two different, equally
// correct expressions for the same hand are both accepted. See Section 7
// of the project handout.
//
// The autograder accepts a valid expression whether or not it has an
// extra pair of outermost parentheses -- both "(7*(4-(4/7)))" and
// "7*(4-(4/7))" are fine. You do not need to simplify or prettify the
// expression string before returning it.
//
// Compile:
//   g++ -std=c++17 -Wall -Wextra -o make24 make24.cpp
//
// Run:
//   ./make24

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <exception>
#include <utility>

const double DELTA = 1e-6;
const int GOAL = 24;

// Pairs a running sub-expression's text with its numeric value, so that
// once you find a hand that reduces to a single value equal to GOAL, its
// paired expression string is the answer.
//
// Do not change the name of this struct or its field names, order, or
// types. The autograder uses this exact interface when testing
// arithmetic().
struct Expression_Value {
  std::string expression;
  double value;
};

// A non-empty return value is one valid solution expression.
// An empty string "" means that no solution exists.
std::string make24(std::vector<double> numsVec);
std::string make24(std::vector<Expression_Value> ev_vec);
std::vector<Expression_Value> arithmetic(Expression_Value ev1, Expression_Value ev2);
void print(const std::vector<double>& numsVec);

// ── Helper for main() ─────────────────────────────────────────────────────
static void print_result(int passed, int total) {
  if (passed == total)
    std::cout << "All " << total << " tests passed.\n";
  else
    std::cout << passed << "/" << total << " tests passed.\n";
}

// ── main() — do not modify ────────────────────────────────────────────────
// These are the same example hands worked through in the project handout.
// The Gradescope autograder checks additional hands you have not seen here
// (including some five-number hands), so passing every test below is
// necessary but not sufficient for full credit.
//
// This self-check only confirms whether you found *some* solution when one
// exists (or correctly reported none when it doesn't) -- it does not
// re-verify your expression's arithmetic. For any test that reports a
// found expression, check by hand (or with a calculator) that it actually
// evaluates to 24 using each of the given numbers exactly once.
int main() {
  struct TestCase { std::vector<double> data; bool expectedSolvable; const char* label; };
  std::vector<TestCase> tests = {
    {{24},         true,  "{24}"},
    {{1},          false, "{1}"},
    {{12, 4, 2},   true,  "{12,4,2}"},
    {{1, 2, 4},    false, "{1,2,4}"},
    {{1, 1, 1},    false, "{1,1,1}"},
    {{1, 2, 3, 4}, true,  "{1,2,3,4}"},
    {{4, 4, 7, 7}, true,  "{4,4,7,7}"},
    {{1, 2, 2, 2}, false, "{1,2,2,2}"},
  };

  int pass = 0;
  auto chk = [&](const TestCase& t) {
    try {
      std::string got = make24(t.data);
      bool solvable = !got.empty();
      if (solvable == t.expectedSolvable) {
        pass++;
        if (solvable) {
          std::cout << "  found for " << t.label << ": " << got
                    << "  (verify by hand that this equals 24)\n";
        }
        return;
      }
      std::cout << "FAIL: make24(" << t.label << ") expected "
                << (t.expectedSolvable ? "a solution" : "no solution (\"\")")
                << ", got " << (solvable ? ("\"" + got + "\"") : std::string("\"\"")) << "\n";
    } catch (const std::exception& e) {
      std::cout << "FAIL: make24(" << t.label << ") threw unexpectedly: "
                << e.what() << "\n";
    }
  };

  for (const TestCase& t : tests) chk(t);
  print_result(pass, static_cast<int>(tests.size()));
  return 0;
}

// ════════════════════════════════════════════════════════════════════════
//  IMPLEMENT make24(vector<double>) BELOW
// ════════════════════════════════════════════════════════════════════════
//
// This overload is the entry point the autograder calls. It should do very
// little: convert each number in numsVec into a "trivial" Expression_Value
// (its expression is just its own literal value as a string; its value is
// itself), collect those into a vector, and delegate to the
// make24(vector<Expression_Value>) overload below.
//
// You may assume every entry of numsVec is an integer value (as always in
// this project) and that numsVec contains at least one number.
//
// Hint: std::to_string(static_cast<int>(x)) turns a whole-number double x
// into the text you want for its starting expression.
std::string make24(std::vector<double> numsVec) {
  // TODO
  return "";  // placeholder -- remove this line when you implement the above
}

// ════════════════════════════════════════════════════════════════════════
//  IMPLEMENT make24(vector<Expression_Value>) BELOW
// ════════════════════════════════════════════════════════════════════════
//
// Returns an expression string that evaluates to 24 using every value in
// ev_vec exactly once (each carrying the sub-expression that produced it
// so far), or "" if no such expression exists. See Section 2 of the
// project handout for the full recursive definition and a worked example
// trace; the structure is identical to Task A's make24(), except that
// instead of returning true/false you return (and propagate upward) the
// first solution expression you find.
//
// Base case (size == 1):
//   The hand can make 24 iff its one remaining value is (approximately --
//   see the DELTA discussion in Section 3 of the handout) equal to GOAL.
//   If so, ITS EXPRESSION STRING is the answer.
//
// Recursive case (size >= 2):
//   Consider every pair of positions (i, j) with i < j. For each pair,
//   arithmetic() (also below -- its own TODO) gives every way of combining
//   ev_vec[i] and ev_vec[j] into a single Expression_Value. For each
//   candidate, build a smaller hand by removing positions i and j and
//   appending the candidate, then recurse on that smaller hand. As soon as
//   any pair, any candidate, and the recursive call on the resulting hand
//   returns a non-empty string, that string is your answer -- stop
//   searching and return it immediately. If nothing works for any pair or
//   candidate, return "" (no solution).
//
// ┌─ GOTCHA ──────────────────────────────────────────────────────────────┐
// │  Removing two selected elements by swap() + pop_back() is easy to    │
// │  get subtly wrong. A swap used to remove one selected element may    │
// │  change what value is stored at the other selected index.            │
// │                                                                      │
// │  Since i < j, remove the element at the LARGER index j first.        │
// │  Doing so does not disturb the element at index i. After j has been  │
// │  removed, remove i. Section 2 of the handout works through a full    │
// │  counterexample.                                                     │
// │                                                                      │
// │  Remember: after removing j, cloneVec has size - 1 elements, so its  │
// │  last valid index is size - 2 -- not size - 1.                       │
// └─────────────────────────────────────────────────────────────────────┘
std::string make24(std::vector<Expression_Value> ev_vec) {
  // TODO
  return "";  // placeholder -- remove this line when you implement the above
}

// ── IMPLEMENT arithmetic() BELOW ──────────────────────────────────────────
//
// Returns every well-defined result of combining ev1 and ev2 with +, -, *,
// and /, as Expression_Value objects: each result pairs the computed
// numeric value with the corresponding combined expression string.
//
// Build each expression string as "(" + left + op + right + ")" -- always
// keep the parentheses, even though it looks redundant for a single pair
// right now. Once these results get combined again in a later recursive
// call, the parentheses are what keep the precedence correct (compare
// 5/(2*3) with the wrong, unparenthesized 5/2*3).
//
// Addition and multiplication are commutative, so each needs only one
// entry. Subtraction and division are NOT commutative, so both orders
// matter and both must be included: ev1.value - ev2.value as well as
// ev2.value - ev1.value, and likewise for division. A division is only
// well-defined when its divisor is nonzero -- guard each division
// separately (skip it rather than computing it) when the relevant value
// is within DELTA of zero, exactly as in Task A's arithmetic().
//
// A call with two ordinary nonzero operands should return six results, in
// this order (values shown; build the matching expression string for
// each): ev1+ev2, ev1-ev2, ev2-ev1, ev1*ev2, ev1/ev2, ev2/ev1.
std::vector<Expression_Value> arithmetic(Expression_Value ev1, Expression_Value ev2) {
  // TODO
  return {};  // placeholder -- remove this line when you implement the above
}

// Prints the elements of numsVec on one line, space-separated. Handy for
// tracing your own recursion while debugging; not used by main().
void print(const std::vector<double>& numsVec) {
  for (int i = 0; i < static_cast<int>(numsVec.size()); ++i) {
    std::cout << numsVec[i] << " ";
  }
  std::cout << std::endl;
}
