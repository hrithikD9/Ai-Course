# 🧭 Best-First Search Algorithm

> **Best-First Search** is an informed search algorithm that intelligently explores a graph by always choosing the most promising node according to a heuristic function, combining the advantages of BFS and DFS.

---

## 🔧 How the Algorithm Works

Best-First Search uses heuristic evaluation to guide its exploration:

1. 🏁 Initialize a priority queue with the start node
2. 🔄 While the priority queue is not empty:
   - Remove the most promising node (lowest cost/best heuristic value)
   - If this node is the goal, return the path to it
   - Mark the node as visited
   - Add all unvisited neighbors to the priority queue with their heuristic values
3. ❌ If the queue becomes empty without finding the goal, return failure

Unlike breadth-first search that explores level by level, Best-First Search dynamically selects the most promising node regardless of its depth in the search tree, providing a more directed search.

---

## 🚀 Applications of Best-First Search

| Domain | Use Case |
|--------|----------|
| **Navigation** | Finding efficient routes in maps, GPS systems |
| **Robotics** | Guiding robots through complex environments |
| **Networking** | Optimal path finding in computer networks |
| **Puzzle Solving** | 8-puzzle, 15-puzzle, sliding puzzles |
| **AI Planning** | Planning sequences of actions to reach goals |
| **Resource Management** | Optimizing allocation of limited resources |
| **Game AI** | Decision making in strategy games and simulators |
| **Route Planning** | Traffic navigation and logistics optimization |

---

## ⏱ Complexity Analysis

| Metric | Complexity |
|--------|------------|
| **Time** | `O(b^d)` worst case, where b = branching factor, d = depth |
| **Space** | `O(b^d)` to store nodes in the priority queue |

**Key Performance Notes:**
- With a good heuristic, average case can be much better than worst case
- Efficiency heavily depends on the quality of the heuristic function
- With a perfect heuristic, would only explore nodes along the optimal path
- Typically outperforms uninformed search methods in practice

---

## 📈 Input & Output

### Sample Input
```cpp
// Number of nodes in the graph
int n = 14;

// Graph edges: {source, destination, weight/heuristic}
vector<vector<int>> edgeList = {
    {0, 1, 3}, {0, 2, 6}, {0, 3, 5},
    {1, 4, 9}, {1, 5, 8}, {2, 6, 12},
    {2, 7, 14}, {3, 8, 7}, {8, 9, 5},
    {8, 10, 6}, {9, 11, 1}, {9, 12, 10},
    {9, 13, 2}
};

// Source node
int source = 0;

// Target node
int target = 9;
```

### Sample Output
```
0 1 3 8 9
```

The output represents the path found from source node 0 to target node 9. The algorithm prioritizes nodes with lower edge weights (which act as the heuristic values), exploring the most promising paths first.

In this example:
- Starting at node 0
- Selects node 1 (lowest heuristic of 3)
- Then moves to node 3
- Proceeds to node 8
- Finally reaches the target node 9

This demonstrates how Best-First Search efficiently navigates through a graph by always selecting the most promising node according to the heuristic function.
