# Q2 — 0/1 Knapsack: Viva Terms and Answers

## Algorithm in one sentence
Use **bottom-up dynamic programming** to choose each item either entirely (**1**) or not at all (**0**) while maximizing value without exceeding the capacity.

## Every important term in the given code
| Term / syntax | Definition and role |
|---|---|
| `#include <iostream>` | Standard console input/output. |
| `#include <algorithm>` | Supplies `max()`. |
| `using namespace std;` | Removes need for `std::` qualifications in this program. |
| `int main()`, `return 0;` | Program entry point and successful exit status. |
| `n` | Total number of items. |
| `capacity` | Maximum allowed total weight; generally denoted `W` in complexity analysis. |
| `weight[n]` | Integer weights for all items. |
| `value[n]` | Integer value/profit of all items. |
| `i` | Number of first items currently considered in a DP row (0 through n). |
| `j` | Subproblem capacity represented by a DP column (0 through capacity). |
| `weight[i-1]` | Weight of the current item: array indexes start at 0, DP item counts at 1. |
| `value[i-1]` | Value of the current item. |
| `dp[n+1][capacity+1]` | A two-dimensional DP table with extra row/column for the zero cases. |
| `dp[i][j]` | **Maximum value achievable with the first i items and capacity j.** |
| **State** | Pair `(i,j)` defining the current subproblem. |
| **Base case** | A directly known result; `dp[0][j]=0`, `dp[i][0]=0` under positive-weight assumptions. |
| `i==0 || j==0` | Logical OR: no items or no capacity leads to value zero. |
| `weight[i-1] <= j` | Current item fits in this subproblem's knapsack. |
| `Take` | Value obtained by including current item. |
| `value[i-1] + dp[i-1][j-weight[i-1]]` | Current item's value plus best value using earlier items and remaining capacity. |
| `notTake` | Best value when skipping current item: `dp[i-1][j]`. |
| `max(Take,notTake)` | State transition selecting the better of inclusion or exclusion. |
| **Dynamic programming** | Computes and reuses solutions to overlapping subproblems. |
| **Tabulation** | Bottom-up DP using iterative loops to fill a table. This code uses tabulation, not memoization. |
| **Memoization** | Alternative top-down recursive DP that caches repeated results. |
| **Overlapping subproblems** | Similar states are needed in many candidate solutions. |
| **Optimal substructure** | Best answer uses best answers to smaller subproblems. |
| **0/1 restriction** | An item is chosen at most once; no fractions or duplicate uses. |
| `dp[n][capacity]` | Final optimal value over all items and the full capacity. |
| `for` and nested loops | Traverse all rows and columns in the DP table. |
| `cin >>`, `cout <<`, `endl` | Console input and output, with newline/flush for `endl`. |
| **Time complexity** | **O(nW)** from the rows times capacity columns. |
| **Space complexity** | **O(nW)** for the table; can be optimized to O(W). |
| **Pseudo-polynomial** | The algorithm depends on the numeric value of W, not only the number of bits in W. |
| **Variable-length array (VLA)** | `int dp[n+1][capacity+1]` is not ISO-standard C++; GCC may allow it as an extension. |

## Board explanation of the key formula
`Take = value[i-1] + dp[i-1][j-weight[i-1]]`:
- `value[i-1]`: receive this item's value now.
- `j-weight[i-1]`: the remaining capacity after including it.
- `dp[i-1][...]`: best answer from only earlier items; this prevents taking the same item twice.
- `notTake = dp[i-1][j]`: retain capacity and skip this item.
- `dp[i][j] = max(Take, notTake)`: choose larger profit.

## Important assumptions or pitfalls
1. This code's zero-capacity base case assumes **positive item weights**. Positive-valued, zero-weight items need different handling.
2. Large `n` and `capacity` may exhaust stack memory due to a large local table.
3. Using `vector<vector<int>>` instead of variable-length arrays is portable C++.
4. Fractional Knapsack's ratio-based Greedy method is **not** generally optimal for 0/1 Knapsack.

## Common viva questions — short answers
**Why 0/1?** Each item has exactly two options: selected or not selected.

**Which DP technique is used?** Bottom-up tabulation.

**What is the DP state?** `dp[i][j]` = best value using first i items with capacity j.

**Why start from i=0 and j=0?** To fill the base cases before building larger states.

**Why use i-1?** The arrays are zero-indexed; it also excludes reuse of the current item in the previous-row subproblem.

**Why do we compare Take and notTake?** To choose the optimal decision for the current state.

**What if an item doesn't fit?** Copy `dp[i-1][j]`.

**Can it use O(W) space?** Yes, using a single DP array and iterating capacity backwards.

**Is O(nW) polynomial?** It is pseudo-polynomial in the binary encoding length of W.
