# 🔄 Iterative Deepening Search (IDS) Algorithm

> **Iterative Deepening Search** is a hybrid search strategy that combines the best aspects of depth-first search (memory efficiency) and breadth-first search (completeness and optimality) by running depth-limited searches with progressively increasing depth limits.

---

## 🔧 How the Algorithm Works

IDS performs a series of increasingly deeper searches:

1. 🏁 Start with a depth limit of 0
2. 🔍 Perform a depth-limited search (DLS) with the current depth limit
3. ✅ If the goal is found, return the solution
4. ⬆️ If not, increment the depth limit and repeat the search from step 2
5. 🔄 Continue until either:
   - The goal is found (success)
   - The maximum depth is reached (failure)
   - The entire search space is exhausted (failure)

This approach gives us a "best of both worlds" solution that finds optimal paths while maintaining memory efficiency.

---

## 🚀 Applications of IDS

| Domain | Use Case |
|--------|----------|
| **Puzzle Solving** | Finding solutions with minimal steps |
| **Path Planning** | Finding shortest paths in unweighted graphs |
| **Game AI** | Game tree exploration for optimal moves |
| **Automated Planning** | Finding optimal action sequences |
| **Network Routing** | Finding paths with minimal hops |
| **Web Crawling** | Methodical web page exploration |
| **File Systems** | Searching through nested directories |
| **State Space Search** | Solving complex state-space problems |

---

## ⏱ Complexity Analysis

| Metric | Complexity |
|--------|------------|
| **Time** | `O(b^d)` where b = branching factor, d = shallowest goal depth |
| **Space** | `O(d)` where d = current depth limit |

**Key Performance Notes:**
- Although shallow nodes are expanded multiple times, most computational work happens at the deepest level
- Much more memory-efficient than BFS, which requires `O(b^d)` space
- Optimal like BFS: always finds the shortest path in unweighted graphs
- Space-efficient like DFS: only needs to store current path being explored
- Re-expansion overhead is usually negligible compared to memory savings

---

## 📈 Input & Output

### Sample Input
```
8 9
1 2
1 3
1 4
2 5
2 6
3 7
4 7
5 8
6 8
1 8 3
```
This represents:
- A graph with 8 vertices and 9 edges
- The edges: (1,2), (1,3), (1,4), (2,5), (2,6), (3,7), (4,7), (5,8), (6,8)
- Starting node: 1
- Target node: 8
- Maximum depth: 3

### Sample Output
```
Depth 0: 1 
Depth 1: 1 2 3 4 
Depth 2: 1 2 5 6 3 7 4 
Depth 3: 1 2 5 8 
Target found at depth 3
```

In this example:
1. The algorithm starts with a depth limit of 0, only exploring the start node
2. It increases the depth to 1, exploring direct neighbors of node 1
3. At depth 2, it explores nodes up to 2 steps away from the start
4. At depth 3, it finds the target node 8 via path 1 → 2 → 5 → 8

The output shows how IDS methodically explores the graph at increasing depths until finding the target. This ensures that the shortest path is found while maintaining memory efficiency.
