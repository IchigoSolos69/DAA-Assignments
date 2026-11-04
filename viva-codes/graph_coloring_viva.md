# Q4 — Graph Coloring: Viva Terms and Answers

## Algorithm in one sentence
Find the minimum number of colors needed to color vertices so adjacent vertices differ, using **recursive backtracking**. Your program tries color limits `m=1` through `v`.

## Every important term in the given code
| Term / syntax | Definition and role |
|---|---|
| `#include <iostream>` | Console input/output. |
| `#define MAX 10` | Preprocessor macro setting the maximum number of vertices to ten. |
| `graph[MAX][MAX]` | 10x10 adjacency matrix holding zeroes or ones for edges. |
| `color[MAX]` | Array of assigned color IDs; 0 means uncolored. |
| `v` | Number of graph vertices. |
| `m` | Maximum number of distinct colors currently allowed. |
| `Vertex` | Zero-based index of the vertex currently being assigned a color. |
| `c` | A candidate color ID from 1 to `m`. |
| `i`, `j` | Loop indices used to read/check the graph. |
| `bool` | C++ Boolean type. |
| `true` / `false` | Success / failure or valid / invalid Boolean values. |
| `isSafe(Vertex,c)` | Checks all neighbors for a conflict with candidate color `c`. |
| `graph[Vertex][i]==1` | Tests whether an edge connects Vertex to i. |
| `color[i]==c` | Tests whether neighbor i has the same candidate color. |
| `&&` | Logical AND: both adjacency and equal colors must hold for a conflict. |
| `return false` in `isSafe` | Rejects a conflicting color. |
| `return true` in `isSafe` | No already-colored neighbor has that color. |
| `graphColoring(Vertex)` | Recursive function exploring feasible color assignments. |
| `Vertex==v` | Base case: all vertices have been colored successfully. |
| `for(int c=1;c<=m;c++)` | Tries candidate colors one by one. |
| `color[Vertex]=c` | Commits a provisional color. |
| `graphColoring(Vertex+1)` | Recursively attempts to color the next vertex. |
| `color[Vertex]=0` | **Backtracking step:** undo the attempted color on failure. |
| `for(m=1;m<=v;m++)` | Tries increasing color limits to find the smallest feasible number. |
| **Graph** | Set of vertices (nodes) and edges (connections). |
| **Vertex** | Node in a graph. |
| **Edge** | Connection between two vertices. |
| **Adjacent** | Two vertices are connected by an edge. |
| **Adjacency matrix** | Matrix representing edges between each pair of vertices. |
| **Undirected graph** | An edge is symmetric between endpoints; matrix should be symmetric. |
| **Proper vertex coloring** | No two adjacent vertices share the same color. |
| **Chromatic number** | Minimum colors required for a proper vertex coloring, written chi(G). |
| **M-coloring** | Decision problem: can graph be colored using at most m colors? |
| **Backtracking** | Search strategy that tries choices and undoes choices that cannot lead to a solution. |
| **Recursion** | Function calls itself on another vertex. |
| **State-space tree** | Conceptual tree of all partial assignments explored. |
| **Pruning** | Skipping branches early when adjacency constraints are violated. |
| **Constraint satisfaction** | Searching for assignments that satisfy adjacency restrictions. |
| **Space complexity** | O(V²) adjacency matrix plus O(V) colors and recursion. |
| **Time complexity** | Exponential in general; for a fixed m, a loose upper bound is O(V*m^V) with O(V) safety checks. |

## Key program flow
1. Read `v` and a v-by-v adjacency matrix.
2. Start with only one allowed color (`m=1`).
3. Reset color assignments to 0.
4. Run `graphColoring(0)`.
5. For each vertex, try safe colors; recursively process the next vertex.
6. Undo assignment `color[Vertex]=0` when subsequent vertices cannot be colored.
7. Increase m until the first valid coloring is found: that m is the chromatic number.

## Important assumptions and limitations
- Intended input is a **simple, undirected graph**: matrix symmetric, entries 0/1 and diagonal entries zero.
- A **self-loop** makes proper graph coloring impossible, but this implementation does not correctly detect self-loops before assigning colors.
- This implementation restricts the graph to **1 through 10 vertices**.
- It finds exact chromatic number for valid simple graphs, but exponential backtracking becomes expensive on large graphs.

## Common viva questions — short answers
**What is graph coloring?** Assigning colors to vertices so neighboring vertices differ.

**What is the chromatic number?** Minimum number of colors in a valid proper coloring.

**What is the algorithmic technique?** Backtracking with recursion.

**What does isSafe do?** Rejects a color already used by an adjacent vertex.

**Which line backtracks?** `color[Vertex]=0;`.

**What is the recursion base case?** `Vertex==v`.

**Why loop over m from 1 to v?** To find the first and thus minimum feasible color count.

**When might backtracking be expensive?** When many possible assignments must be explored before proving success/failure.

**Where used?** Exam timetabling, frequency assignment, register allocation and scheduling.
