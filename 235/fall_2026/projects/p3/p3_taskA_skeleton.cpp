// File name: make24.cpp  (rename this file to make24.cpp before submitting)
// Name:
// Email:
//
// P3 — Make 24, Task A: Boolean Solver
//
// Implement make24() and arithmetic() below.
// The main() test harness is already written; do not modify it.
//
// Compile:
//   g++ -std=c++17 -Wall -Wextra -o make24 make24.cpp
//
// Run:
//   ./make24

#include <iostream>
#include <vector>
#include <cmath>
#include <exception>
#include <utility>

const double DELTA = 1e-6;
const int GOAL = 24;

bool make24(std::vector<double> numsVec);
std::vector<double> arithmetic(double num, double num2);
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
int main() {
  struct TestCase { std::vector<double> data; bool expected; const char* label; };
  std::vector<TestCase> tests = {
    {{24},         true,  "{24}"},
    {{1},          false, "{1}"},
    {{12, 4, 2},   true,  "{12,4,2} -- 12*4/2"},
    {{1, 2, 4},    false, "{1,2,4}"},
    {{1, 1, 1},    false, "{1,1,1}"},
    {{1, 2, 3, 4}, true,  "{1,2,3,4} -- 1*2*3*4"},
    {{4, 4, 7, 7}, true,  "{4,4,7,7} -- 7*(4-4/7)"},
    {{1, 2, 2, 2}, false, "{1,2,2,2}"},
  };

  int pass = 0;
  auto chk = [&](const TestCase& t) {
    try {
      bool got = make24(t.data);
      if (got == t.expected) { pass++; return; }
      std::cout << "FAIL: make24(" << t.label << ") expected "
                << std::boolalpha << t.expected << ", got " << got << "\n";
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
//  IMPLEMENT make24() BELOW
// ════════════════════════════════════════════════════════════════════════
//
// Returns true iff every number in numsVec can be combined -- using each
// number exactly once, with +, -, *, /, and any parenthesization -- to
// produce 24. See Section 2 of the project handout for the full recursive
// definition and a worked example trace.
//
// You may assume numsVec contains at least one number; you do not need to
// handle the empty-vector case.
//
// Base case (size == 1):
//   The hand can make 24 iff its one remaining value is (approximately --
//   see the DELTA discussion in Section 3 of the handout) equal to GOAL.
//
// Recursive case (size >= 2):
//   Consider every pair of positions (i, j) with i < j. For each pair,
//   arithmetic() (also below -- its own TODO) gives every way of combining
//   numsVec[i] and numsVec[j] into a single value. For each candidate
//   value, build a smaller hand by removing positions i and j and
//   appending the candidate, then recurse on that smaller hand. If any
//   pair, any candidate, and the recursive call on the resulting hand
//   returns true, the whole hand can make 24. If nothing works for any
//   pair or candidate, the hand cannot make 24.
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
bool make24(std::vector<double> numsVec) {
  // TODO
  return false;  // placeholder -- remove this line when you implement the above
}

// ── IMPLEMENT arithmetic() BELOW ──────────────────────────────────────────
//
// Returns every well-defined result of combining num and num2 with +, -,
// *, and /.
//
// Addition and multiplication are commutative (num + num2 is the same
// value as num2 + num), so each needs only one entry. Subtraction and
// division are NOT commutative, so both orders matter and both must be
// included: num - num2 as well as num2 - num, and likewise for division.
//
// A division is only well-defined when its divisor is nonzero. Guard each
// division separately (skip it rather than computing it) when the
// relevant operand is within DELTA of zero -- see Section 3 of the
// handout for why comparing against DELTA is safer here than testing
// == 0 exactly.
//
// A call with two ordinary nonzero operands should return six values, in
// this order: num+num2, num-num2, num2-num, num*num2, num/num2, num2/num.
std::vector<double> arithmetic(double num, double num2) {
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
