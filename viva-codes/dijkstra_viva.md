# Q5 — Dijkstra's Algorithm: Viva Terms and Answers

## Algorithm in one sentence
Compute **single-source shortest distances** in a graph with **non-negative edge weights** by repeatedly finalizing the unvisited vertex with minimum tentative distance, then **relaxing** its outgoing edges.

## Every important term in the given code
| Term / syntax | Definition and role |
|---|---|
| `#include <iostream>` | Console I/O. |
| `#include <climits>` | Defines integer limit constants such as `INT_MAX`. |
| `#define INF INT_MAX` | Macro using the largest `int` value as a stand-in for infinite/unreachable distance. |
| `INT_MAX` | Maximum value of an `int` on the platform (commonly 2,147,483,647). |
| `void dijkstra(...)` | Function computing shortest distances; no return value. |
| `graph[10][10]` | Weighted adjacency matrix of at most ten vertices. |
| `V` | Total number of vertices. |
| `src` | Zero-based source/start vertex. |
| `dist[10]` | Best currently known distances from source to each vertex. |
| `visited[10]` | Whether a vertex's shortest distance has been finalized. |
| `dist[i] = INF` | Initializes distance estimates as unknown/unreachable. |
| `visited[i] = false` | Marks vertex as not finalized. |
| `dist[src] = 0` | The source has zero distance to itself. |
| `count` | Outer loop index controlling up to V-1 iterations. |
| `u=-1` | Sentinel indicating no next vertex has yet been selected. |
| `min=INF` | Current minimum tentative distance in the selection scan. |
| `i` | Loop index when initializing or searching all vertices. |
| `u` | Next unvisited vertex of minimum tentative distance. |
| `v` | Potential neighboring vertex being relaxed. |
| `!visited[i]` | Logical NOT: vertex is not finalized. |
| `dist[i] < min` | Finds a better candidate for the next greedy selection. |
| `u == -1` | No reachable unvisited vertex remains; stop. |
| `break` | Ends the main selection loop. |
| `visited[u] = true` | Finalizes the shortest distance to u. |
| `graph[u][v] != 0` | Treats nonzero matrix entry as an edge; cannot represent a real zero-weight edge. |
| `dist[u] != INF` | Checks that u has a finite-known distance. |
| `dist[u] + graph[u][v] < dist[v]` | Checks if passing through u gives a shorter route to v. |
| `dist[v] = dist[u] + graph[u][v]` | **Relaxation:** updates v's best-known distance. |
| `\n` | Newline escape sequence. |
| `\t` | Tab escape sequence. |
| **Weighted graph** | Edges carry numerical costs such as distance or travel time. |
| **Directed graph** | An edge u→v need not imply v→u; Dijkstra handles directed graphs. |
| **Undirected graph** | Each edge can be traveled both ways; symmetric matrix. |
| **Shortest path** | Path with minimum sum of edge weights. |
| **Single-source shortest path** | Shortest path distances from one chosen source to other vertices. |
| **Greedy algorithm** | Selects the locally smallest tentative distance to finalize at each step. |
| **Tentative distance** | Best distance found so far; may improve before finalization. |
| **Visited/finalized vertex** | Vertex whose shortest distance is guaranteed optimal under non-negative weights. |
| **Edge relaxation** | Trying to lower the current path estimate through an edge. |
| **Disconnected/unreachable** | No path from source; `dist` remains INF. |
| **Priority queue** | Efficient min-key retrieval structure used in optimized Dijkstra variants (not used in this code). |
| **Time complexity** | **O(V²)** with adjacency matrix and linear scans, as in this code. |
| **Auxiliary space** | **O(V)** for dist/visited, plus O(V²) to store adjacency matrix. |

## The relaxation formula
`dist[v] = min(dist[v], dist[u] + weight(u,v))`

If `dist[u]=3`, edge `u→v` costs 4, and `dist[v]=10`, then new route cost 7 is better, so `dist[v]` becomes 7.

## Important assumptions and pitfalls
1. Edge weights **must be non-negative** for Dijkstra's greedy guarantee.
2. This code interprets **0 as no edge**, so it cannot represent valid zero-weight edges.
3. Even with `dist[u]!=INF`, adding very large positive weights may overflow an `int`.
4. Source must be within `0..V-1`; the code's source error message suggesting 1–10 is misleading.
5. The code prints **distances**, not actual paths; add a `parent[]` array to reconstruct paths.
6. Maximum supported vertices is ten.

## Common viva questions — short answers
**What does Dijkstra compute?** Minimum distance from one source to all reachable vertices.

**Which technique does it use?** Greedy.

**What is the greedy choice?** Finalize the unvisited vertex with the smallest tentative distance.

**What is relaxation?** Updating an estimate when an edge provides a shorter path.

**Why is source distance zero?** Zero-length path from a vertex to itself.

**Why INF initially?** No route is known yet to those vertices.

**What if a vertex is unreachable?** It retains INF and is printed as `No path.`.

**Can it handle negative edges?** Not reliably; use a suitable algorithm such as Bellman–Ford.

**Can it handle directed graphs?** Yes, with non-negative weights.

**What is its complexity in your implementation?** O(V²); heap-based adjacency-list versions often use O((V+E)log V).
