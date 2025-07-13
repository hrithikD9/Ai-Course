# 🌟 A* (A-Star) Algorithm

> **A* Search** is an informed search algorithm that combines the strengths of Dijkstra's algorithm and greedy best-first search, finding the shortest path by evaluating both the cost so far and the estimated cost to the goal.

---

## 🔧 How the Algorithm Works

A* intelligently combines path cost and heuristic estimation:

1. 🏁 Start at the source node with priority based on f(n) = g(n) + h(n), where:
   - g(n): Actual cost from start to current node
   - h(n): Heuristic estimate from current node to goal
   
2. 🔄 While the priority queue is not empty:
   - Remove node with lowest f-value
   - If this is the goal node, return the path
   - Mark the node as visited
   - For each neighbor:
     - Calculate tentative g-value (cost so far + edge cost)
     - If new path to neighbor is better than any previous one:
       - Update g-value for this neighbor
       - Set f-value = g-value + heuristic
       - Add neighbor to priority queue with new path
       
3. 🎯 When goal is found, reconstruct and return the optimal path
4. ❌ If queue empties without reaching goal, no path exists

A* is guaranteed to find the shortest path when using an admissible heuristic (one that never overestimates the actual cost).

---

## 🚀 Applications of A* Search

| Domain | Use Case |
|--------|----------|
| **Video Games** | Pathfinding for NPCs in games like Warcraft, Starcraft |
| **Robotics** | Robot motion planning, obstacle avoidance |
| **GPS Systems** | Finding optimal routes between locations |
| **Network Routing** | Finding efficient paths in computer networks |
| **Puzzle Solving** | Solving 8-puzzle, 15-puzzle, and similar problems |
| **Logistics** | Package delivery route optimization |
| **AI Planning** | Finding optimal action sequences |
| **Computer Vision** | Image analysis and feature matching |

---

## ⏱ Complexity Analysis

| Metric | Complexity |
|--------|------------|
| **Time** | `O(b^d)` worst case, where b = branching factor, d = depth |
| **Space** | `O(b^d)` to store all generated nodes |

**Key Performance Factors:**
- With a perfect heuristic, complexity reduces to `O(n)` where n = path length
- With poor heuristics, degrades to Dijkstra's algorithm (`O(E + V log V)`)
- Heuristic quality dramatically affects performance
- Space complexity can be a limitation for very large graphs

---

## 📈 Sample Input & Output

### ⌨️ Input Example

```
Enter number of nodes: 5
Enter heuristic values for each node:
Node 1: 0 10
Node 2: 1 8
Node 3: 2 5
Node 4: 3 3
Node 5: 4 0
Enter number of edges: 6
Is the graph undirected? (1 for Yes, 0 for No): 1
Enter edges with cost (format: from to cost):
0 1 2
0 2 3
1 2 1
1 3 5
2 3 2
3 4 4
Enter start node: 0
Enter goal node: 4
```

### 🖥️ Output Example

```
A* Path from 0 to 4: 0 2 3 4
```

### 📊 Explanation

In this example:
- We created a graph with 5 nodes (0-4) and assigned heuristic values to each
- Node 0 is the start with heuristic 10, node 4 is the goal with heuristic 0
- The optimal path found by A* is: 0 → 2 → 3 → 4 with a total path cost of 9
- The algorithm avoided the longer path through node 1

The A* algorithm efficiently balances the actual path cost and the heuristic estimate to find the shortest path. When the heuristic is admissible (never overestimates), A* guarantees an optimal solution.
