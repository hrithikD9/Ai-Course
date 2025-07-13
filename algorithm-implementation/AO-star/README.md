# 🧩 AO* (AND-OR Star) Algorithm

> **AO* Search** is an algorithm used for solving problems that can be represented as AND-OR graphs, where certain goals may require satisfying multiple subgoals simultaneously, making it particularly useful for problems with non-deterministic actions.

---

## 🔧 How the Algorithm Works

AO* extends A* to handle problems with AND-OR decompositions:

1. 🏁 Start with an initial problem state (root node)
2. 🔄 Iteratively:
   - Select a most promising path to an unsolved node using heuristic evaluation
   - Expand this node to generate its successors
   - Update the cost/heuristic estimates of affected nodes
   - Update the best partial solution graph
3. 🎯 Continue until the root problem is solved or determined unsolvable

In this implementation, a simplified approach is used where:
- Each node has a heuristic value
- The algorithm starts at a user-specified node
- At each step, it moves to the neighbor with the lowest heuristic value
- The process continues until reaching a node with no better neighbors (a local optimum)

This approach works similarly to a best-first search or hill climbing algorithm guided by heuristic values.

---

## 🚀 Applications of AO* Search

| Domain | Use Case |
|--------|----------|
| **AI Planning** | Planning under uncertainty with multiple goal conditions |
| **Game AI** | Decision making in games with probabilistic outcomes |
| **Robotics** | Robot planning with uncertain action outcomes |
| **Medical Diagnosis** | Determining optimal sequences of tests and treatments |
| **Problem Solving** | Decomposing complex problems into subproblems |
| **Expert Systems** | Knowledge-based systems with conditional reasoning |
| **Decision Support** | Systems that evaluate multiple criteria simultaneously |
| **Risk Analysis** | Evaluating scenarios with multiple dependent outcomes |

---

## ⏱ Complexity Analysis

| Metric | Complexity |
|--------|------------|
| **Time** | `O(b^d)` worst case, where b = branching factor, d = depth |
| **Space** | `O(b^d)` to store the search graph |

**Key Performance Notes:**
- Proper heuristic design is critical for efficiency
- Performance depends heavily on the structure of the AND-OR graph
- The simplified implementation provided has:
  - Time: `O(V+E)` where V = vertices, E = edges
  - Space: `O(V)` for graph storage

---

## 📈 Sample Input & Output

### ⌨️ Input Example

```
Enter number of nodes: 6
Enter heuristic values:
10 8 5 3 7 2
Enter number of edges: 7
Enter edges (u v):
0 1
0 2
1 3
2 3
2 4
3 5
4 5
Enter start node: 0
```

### 🖥️ Output Example

```
Current: 0 with h=10
Current: 2 with h=5
Current: 3 with h=3
Current: 5 with h=2
Reached peak at node: 5
```

### 📊 Explanation

In this example:
- We created a graph with 6 nodes (0-5) and assigned heuristic values to each
- Node 0 is the start with heuristic 10
- The algorithm follows a path of decreasing heuristic values: 0 → 2 → 3 → 5
- Node 5 has the lowest heuristic value (2) among all visited nodes
- The search terminates at node 5 since it has no neighbors with lower heuristic values

The implementation demonstrates a simplified approach focused on finding a local optimum by always moving to the neighbor with the best (lowest) heuristic value until no better neighbor exists.
