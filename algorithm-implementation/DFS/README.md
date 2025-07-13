# 🔍 Depth-First Search (DFS) Algorithm

> **Depth-First Search** is a graph traversal algorithm that explores as far as possible along each branch before backtracking, making it excellent for maze solving, topological sorting, and cycle detection.

---

## 🔧 How the Algorithm Works

DFS dives deep into a graph, exploring each path completely before backtracking:

1. 🏁 Start at a specified source node
2. ✅ Mark the current node as visited and process it
3. 🔄 For each unvisited neighbor of the current node:
   - Recursively apply the DFS algorithm to that neighbor
4. 🔙 If all neighbors have been visited, backtrack

DFS can be implemented using:
* **Recursion**: Using the system's call stack
* **Explicit Stack**: Using a stack data structure following Last-In-First-Out (LIFO) ordering

The implementation in this repository uses an explicit stack for iteration, processing neighbors in reverse order to maintain consistent traversal.

---

## 🚀 Applications of DFS

| Domain | Use Case |
|--------|----------|
| **Graph Analysis** | Topological sorting, cycle detection |
| **Maze Solving** | Finding paths in mazes and labyrinths |
| **Component Analysis** | Identifying connected regions in images or graphs |
| **Puzzle Solving** | Sudoku, crosswords, and backtracking problems |
| **Network Analysis** | Finding strongly connected components |
| **Web Crawling** | Deep exploration of website hierarchies |
| **Game Development** | Generating mazes and exploring game trees |
| **Compiler Design** | Expression parsing and syntax analysis |

---

## ⏱ Complexity Analysis

| Metric | Complexity |
|--------|------------|
| **Time** | `O(V + E)` where V is vertices and E is edges |
| **Space** | `O(V)` for stack and visited set storage |
|           | `O(h)` for recursion depth (h = max depth, up to V) |

**Key Performance Notes:**
- Each vertex is processed exactly once: `O(V)`
- Each edge is considered exactly once: `O(E)`
- DFS is memory-efficient for deep graphs compared to BFS, as it only stores a single path from root to current node

---

## 📈 Input & Output

### Sample Input
```python
graph = {
  'A' : ['B','G'],
  'B' : ['C', 'D', 'E'],
  'C' : [],
  'D' : [],
  'E' : ['F'],
  'F' : [],
  'G' : ['H'],
  'H' : ['I'],
  'I' : [],
}

# Starting node
start_node = 'A'
```

### Sample Output
```
A B E F D C G H I
```

The output shows the exact order in which DFS traverses the graph nodes, starting from node 'A'. This order demonstrates the depth-first nature of the algorithm:
1. It first visits 'A'
2. Then dives deep along the first branch: 'A' → 'B' → 'E' → 'F' (until reaching a leaf)
3. Backtracks and visits: 'B' → 'D' (leaf)
4. Backtracks and visits: 'B' → 'C' (leaf)
5. Backtracks to 'A' and explores the second branch: 'A' → 'G' → 'H' → 'I'

This traversal pattern shows how DFS explores as far as possible along each branch before backtracking to explore other branches.
