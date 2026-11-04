# Q1 — Fractional Knapsack: Viva Terms and Answers

## Algorithm in one sentence
Choose items by **descending value-to-weight ratio**, taking entire items where possible and a fraction of the next item when capacity runs out. This is a **greedy maximization** algorithm.

## Every important term in the given code
| Term / syntax | Definition and role |
|---|---|
| `#include <iostream>` | Includes C++ standard input/output declarations. |
| `#include <algorithm>` | Includes standard algorithms/utilities; `swap` can be obtained here. |
| `using namespace std;` | Lets code use `cout`, `cin`, etc. without the `std::` prefix. |
| `int main()` | Entry point of the program; returns an integer exit status. |
| `int` | Integer data type; used for item count, loop indices and (currently) capacity. |
| `float` | Floating-point type; used for weight, profit, ratios, and total value. |
| `n` | Number of items. |
| `capacity` | Weight that can still fit into the knapsack; initially its maximum capacity. |
| `weight[n]` | Array of the weight of each item. |
| `value[n]` | Array of the monetary value/profit of each item. |
| `ratio[n]` | Array of value-per-unit-weight scores for each item. |
| `ratio[i] = value[i] / weight[i]` | Computes **profit density** or value-to-weight ratio for item `i`. Weight must be positive. |
| `i`, `j` | Zero-based indices used for item traversal and sorting comparisons. |
| `for` | A counted iteration loop; `i++` increments the index after the loop body. |
| `if` / `else` | Conditional branching, here whole-item versus fractional-item selection. |
| `ratio[i] < ratio[j]` | Checks whether a later item has a better profit density and should come first. |
| `swap(a,b)` | Exchanges two values. Swapping weight, value and ratio together preserves each item's association. |
| **Descending order** | Highest ratio first; achieved here with nested pairwise comparisons. |
| **Greedy choice** | Locally best available item is selected first. |
| **Knapsack capacity constraint** | Total selected weight must not exceed `capacity`. |
| `weight[i] <= capacity` | Tests whether the entire item fits in the remaining knapsack. |
| `totalValue` | Running sum of profits obtained from selected items. |
| `(float)capacity` | A C-style explicit conversion; redundant here because `weight[i]` is already `float`. |
| `value[i] * (capacity / weight[i])` | Profit earned by taking only the fraction that fits. |
| `break` | Stops the selection loop as soon as the knapsack is filled. |
| `cin >>` | Reads user input. |
| `cout <<` | Prints information. |
| `endl` | Prints a newline and flushes the output stream. |
| `return 0` | Indicates successful termination. |
| **Array indexing** | An array of length `n` has legal indices `0` through `n-1`. |
| **Variable-length array (VLA)** | `float weight[n]` is a GCC extension, **not standard C++**. Prefer `vector<float>`. |
| **Time complexity** | Growth of runtime with the number of items. Given nested sorting loops: **O(n²)**; selection O(n). |
| **Auxiliary/total storage** | Three item arrays require O(n) memory. |

## Key expressions to explain at the board
- `ratio[i] = value[i] / weight[i];` — higher ratio gives more profit per unit weight.
- `swap(weight[i],weight[j])` + similar swaps — sort corresponding fields together.
- `capacity = capacity - weight[i];` — update the remaining knapsack weight.
- `totalValue += value[i] * (capacity / weight[i]);` — take exactly the fraction of the final item that fits.

## Important code issues the examiner may ask about
1. **Out-of-bounds bug:** `for(int i=0; i<=n; i++)` must be `i<n` while reading item arrays.
2. **Incorrect output:** `cout<<"The maximum value = ",totalValue;` uses the comma operator and does **not** print the total. Use `cout << "The maximum value = " << totalValue;`.
3. **Capacity truncation:** `capacity` is `int` despite fractional weights being `float`; use floating-point capacity to avoid truncation.
4. **Invalid input:** protect against zero/negative weights and nonsensical item counts.
5. Original files are provided unchanged for study; these fixes are **not applied automatically**.

## Common viva questions — short answers
**What is Fractional Knapsack?** Maximizing total value within a capacity when portions of items may be taken.

**Why Greedy?** The globally optimal solution for the standard divisible-item case is achieved by selecting items in decreasing value/weight ratio.

**Can we split an item?** Yes; that's what distinguishes Fractional from 0/1 Knapsack.

**Which sort order?** Descending order by value/weight ratio.

**Why swap three arrays?** To keep the weight, value and computed ratio belonging to each item aligned.

**What is the complexity of this exact code?** O(n²) time due to its nested sorting loops.

**How could sorting be faster?** Use `std::sort` for O(n log n) sorting on records.

**What is the objective function?** Maximize sum of selected item values subject to total selected weight not exceeding capacity.
