// CSCI 235 -- Class 16 review code: pruning and early termination.
// Compile: g++ -std=c++17 -Wall -o review class16_review_code.cpp && ./review
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

// ---------- 1. Subset sum: rem = how much of the target is still needed ----------
int calls = 0;  // counts every function entry, including the root

// Tests are made at function ENTRY, in this order: rem == 0, k == n, then (if enabled) pruning.
// mode 0: only early termination.  mode 1: + "rem < 0" test.  mode 2: + "rem > suffix[k]" test.
bool subsetSum(const std::vector<int>& v, const std::vector<int>& suffix,
               int k, int rem, std::vector<int>& chosen, int mode) {
    ++calls;
    if (rem == 0) return true;                       // goal: exact amount reached
    if (k == (int)v.size()) return false;            // no numbers left
    if (mode >= 1 && rem < 0) return false;          // overshot (safe for nonnegative numbers)
    if (mode >= 2 && rem > suffix[k]) return false;  // even taking everything is not enough
    chosen.push_back(v[k]);                          // take v[k]
    if (subsetSum(v, suffix, k + 1, rem - v[k], chosen, mode)) return true;  // early termination
    chosen.pop_back();                               // undo
    return subsetSum(v, suffix, k + 1, rem, chosen, mode);                   // skip v[k]
}

void runSubsetSum(std::vector<int> v, int target, int mode) {
    std::vector<int> suffix(v.size() + 1, 0);
    for (int k = (int)v.size() - 1; k >= 0; --k) suffix[k] = suffix[k + 1] + v[k];
    std::vector<int> chosen;
    calls = 0;
    bool ok = subsetSum(v, suffix, 0, target, chosen, mode);
    std::cout << "  target " << target << ", mode " << mode << ": " << (ok ? "found {" : "no solution")
              << "";
    if (ok) { for (size_t i = 0; i < chosen.size(); ++i) std::cout << (i ? ", " : "") << chosen[i]; std::cout << "}"; }
    std::cout << "  (" << calls << " calls)\n";
}

// ---------- 2. Duplicate letters ----------
int pcalls = 0;
void printAll(std::string s, int k, int& lines) {
    ++pcalls;
    if (k == (int)s.size()) { ++lines; return; }
    for (int i = k; i < (int)s.size(); ++i) {
        std::swap(s[k], s[i]);
        printAll(s, k + 1, lines);
        std::swap(s[k], s[i]);
    }
}
void printUnique(std::string s, int k, std::vector<std::string>& out) {
    ++pcalls;
    if (k == (int)s.size()) { out.push_back(s); return; }
    std::set<char> tried;                 // LOCAL: fresh for every call
    for (int i = k; i < (int)s.size(); ++i) {
        if (tried.count(s[i])) continue;  // this letter was already tried at position k
        tried.insert(s[i]);
        std::swap(s[k], s[i]);
        printUnique(s, k + 1, out);
        std::swap(s[k], s[i]);
    }
}

// ---------- 3. N-Queens: pruning vs. early termination ----------
int qcalls = 0;
bool safe(const std::vector<int>& cols, int row, int col) {
    for (int r = 0; r < row; ++r)
        if (cols[r] == col || std::abs(cols[r] - col) == row - r) return false;
    return true;
}
// prune: check each placement immediately.  firstOnly: stop at the first solution.
bool queens(int n, int row, std::vector<int>& cols, bool prune, bool firstOnly) {
    ++qcalls;
    if (row == n) {
        if (!prune)  // without pruning we only check at the very end
            for (int r = 0; r < n; ++r) {
                std::vector<int> head(cols.begin(), cols.begin() + r);
                if (!safe(head, r, cols[r])) return false;
            }
        return true;
    }
    bool any = false;
    for (int c = 0; c < n; ++c) {
        if (prune && !safe(cols, row, c)) continue;
        cols.push_back(c);
        if (queens(n, row + 1, cols, prune, firstOnly)) {
            if (firstOnly) return true;
            any = true;
        }
        cols.pop_back();
    }
    return any;
}

// ---------- 4. Tolerance ----------
bool nearlyEqual(double x, double y) { return std::abs(x - y) < 1e-9; }


// ---------- 5. Make 24 call counts (where 9,841 / 4,141 / 139 come from) ----------
long long m24calls = 0;
long long levelCalls[5];   // levelCalls[n] = calls made with n numbers on the table
typedef std::vector<long long> Key;
Key makeKey(const std::vector<double>& nums) {
    Key key;
    for (double x : nums) key.push_back(std::llround(x * 1e6));
    std::sort(key.begin(), key.end());
    return key;
}
// ordered = true: every ordered pair, 4 results.  ordered = false: unordered pairs, 6 results.
bool solve24(std::vector<double> nums, bool ordered, std::set<Key>* seen) {
    ++m24calls; ++levelCalls[nums.size()];
    if (nums.size() == 1) return std::abs(nums[0] - 24) < 1e-9;
    if (seen && !seen->insert(makeKey(nums)).second) return false;   // seen before
    int n = (int)nums.size();
    for (int i = 0; i < n; ++i)
        for (int j = ordered ? 0 : i + 1; j < n; ++j) {
            if (i == j) continue;
            double a = nums[i], b = nums[j];
            std::vector<double> rest;
            for (int t = 0; t < n; ++t) if (t != i && t != j) rest.push_back(nums[t]);
            std::vector<double> res = {a + b, a * b, a - b};   // order: a+b, a*b, a-b, b-a, a/b, b/a
            if (!ordered) res.push_back(b - a);
            if (std::abs(b) > 1e-9) res.push_back(a / b);
            if (!ordered && std::abs(a) > 1e-9) res.push_back(b / a);
            for (double r : res) {
                rest.push_back(r);
                if (solve24(rest, ordered, seen)) return true;
                rest.pop_back();
            }
        }
    return false;
}
void countMake24(std::vector<double> nums, bool ordered, bool useSeen, const char* label) {
    m24calls = 0; for (int i = 0; i < 5; ++i) levelCalls[i] = 0;
    std::set<Key> seen;
    solve24(nums, ordered, useSeen ? &seen : nullptr);
    std::cout << "  " << label << ": " << m24calls << " calls  (by numbers left: 4->" << levelCalls[4]
              << ", 3->" << levelCalls[3] << ", 2->" << levelCalls[2] << ", 1->" << levelCalls[1] << ")\n";
}

int main() {
    std::cout << "1. Subset sum, v = {6, 1, 2}, target 3\n";
    for (int m = 0; m <= 1; ++m) runSubsetSum({6, 1, 2}, 3, m);
    std::cout << "   v = {1, 2, 3, 4}, target 11\n";
    for (int m = 0; m <= 2; ++m) runSubsetSum({1, 2, 3, 4}, 11, m);
    std::cout << "   v = {4, 1, 2, 3}, target 6\n";
    for (int m = 0; m <= 1; ++m) runSubsetSum({4, 1, 2, 3}, 6, m);
    std::cout << "   v = {2, 4, 6}, target 7\n";
    for (int m = 0; m <= 2; ++m) runSubsetSum({2, 4, 6}, 7, m);

    std::cout << "\n2. Duplicate letters\n";
    for (std::string w : {"AAB", "ABC", "AAA", "AABB"}) {
        int lines = 0; pcalls = 0; printAll(w, 0, lines); int ac = pcalls, al = lines;
        std::vector<std::string> out; pcalls = 0; printUnique(w, 0, out);
        std::cout << "  " << w << ": printAll " << ac << " calls, " << al << " lines;  printUnique "
                  << pcalls << " calls, " << out.size() << " lines\n";
    }

    std::cout << "\n3. 4-Queens call counts\n";
    for (int p = 0; p <= 1; ++p)
        for (int f = 0; f <= 1; ++f) {
            std::vector<int> cols; qcalls = 0; queens(4, 0, cols, p, f);
            std::cout << "  prune=" << p << " firstOnly=" << f << ": " << qcalls << " calls\n";
        }

    std::cout << "\n4. Tolerance\n";
    std::cout << "  0.1 + 0.2 == 0.3 ? " << (0.1 + 0.2 == 0.3 ? "true" : "false") << "\n";
    std::cout << "  nearlyEqual(0.1 + 0.2, 0.3) ? " << (nearlyEqual(0.1 + 0.2, 0.3) ? "true" : "false") << "\n";

    std::cout << "\n5. Make 24 call counts for {1, 1, 1, 1} (no solution) and {3, 3, 8, 8}\n";
    countMake24({1, 1, 1, 1}, true, false, "ordered pairs, 4 results   ");
    countMake24({1, 1, 1, 1}, false, false, "unordered pairs, 6 results");
    countMake24({1, 1, 1, 1}, false, true, "unordered + seen set      ");
    countMake24({3, 3, 8, 8}, false, false, "{3,3,8,8} unordered        ");
    countMake24({3, 3, 8, 8}, false, true, "{3,3,8,8} unordered + seen ");
    return 0;
}
