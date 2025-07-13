# 🔎 Depth-Limited Search (DLS) Algorithm

> **Depth-Limited Search** is a variant of DFS that imposes a maximum limit on exploration depth, preventing the algorithm from getting lost in infinite or extremely deep paths while maintaining memory efficiency.

---

## 🔧 How the Algorithm Works

DLS adds a safety boundary to depth-first exploration:

1. 🏁 Start at a specified source node
2. 📏 Set a maximum depth limit for the search
3. 🔄 Perform a DFS traversal with these key modifications:
   - If current depth exceeds the maximum allowed depth, backtrack
   - If target node is found, mark success and stop the search
4. ⏱️ Continue until either:
   - The target is found
   - All nodes within the depth limit are explored

DLS can be implemented:
* **Recursively**: Using function call stack (as shown in the example code)
* **Iteratively**: Using an explicit stack with depth tracking for each node

---

## 🚀 Applications of DLS

| Domain | Use Case |
|--------|----------|
| **Pathfinding** | Finding paths with limited length or cost |
| **Game Design** | Puzzles with maximum moves allowed |
| **Networking** | Routing with limited hop count |
| **Web Crawling** | Controlled-depth website exploration |
| **Game AI** | Game tree exploration with limited lookahead |
| **Data Systems** | Hierarchical data navigation with depth limits |
| **System Discovery** | Finding resources within limited search radius |
| **AI Planning** | Solving problems with constrained solution depth |

---

## ⏱ Complexity Analysis

| Metric | Complexity |
|--------|------------|
| **Time** | `O(b^l)` where b = branching factor, l = depth limit |
| **Space** | `O(l)` for the recursion stack |

**Key Advantages:**
- Avoids the infinite path problems of standard DFS
- More memory-efficient than BFS for deep graphs
- Provides a practical compromise between search thoroughness and efficiency
- Can be tuned to available computational resources via the depth parameter

---

## 📈 Input & Output

### Sample Input
```
7 8
1 2
1 3
1 4
2 5
2 6
3 7
4 7
5 7
1 7 2
```
This represents:
- A graph with 7 vertices and 8 edges
- The edges: (1,2), (1,3), (1,4), (2,5), (2,6), (3,7), (4,7), (5,7)
- Starting node: 1
- Target node: 7
- Depth limit: 2

### Sample Output
```
1 2 5 6 3 7 
Target found
```

The output shows:
1. The traversal order of nodes visited within the depth limit
2. "Target found" indicates that node 7 was successfully found

In this example:
- The algorithm starts at node 1 and explores within a depth of 2
- It visits node 1, then its neighbors 2, 3, and 4
- From node 2, it visits 5 and 6 (still within depth limit)
- From node 3, it visits 7 (the target) and stops

If we reduced the depth limit to 1, the target would not be found because node 7 is at depth 2 from the starting node.
