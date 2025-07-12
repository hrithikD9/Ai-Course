# Beam Search Execution Trace

## Sample Problem Setup

### Graph Structure
```
Nodes: 6 (0, 1, 2, 3, 4, 5)
Edges: 8 directed edges
Start: 0, Goal: 5, Beam Width: 2

Graph Representation:
    0 (h=10)
   / \
  1   2 (h=8, h=6)
 /|   |\
3 4   4 5 (h=4, h=2, h=2, h=0)
 |     |
 5     5 (h=0)
```

### Heuristic Values
```
Node 0: h=10 (farthest from goal)
Node 1: h=8
Node 2: h=6
Node 3: h=4
Node 4: h=2
Node 5: h=0  (goal node)
```

## Step-by-Step Execution

### Level 0: Initialization
```
Current Beam: [0]
Beam Size: 1
Action: Start search from node 0
```

### Level 1: First Expansion
```
Current Node: 0
Successors: [1, 2]
Heuristic Values: h(1)=8, h(2)=6
Sorted by Heuristic: [2, 1] (lower is better)
New Beam: [2, 1] (keep best 2 nodes)
Beam Size: 2
```

### Level 2: Second Expansion
```
Expanding Node 2:
├── Successors: [4, 5]
├── Heuristics: h(4)=2, h(5)=0

Expanding Node 1:
├── Successors: [3, 4]
├── Heuristics: h(3)=4, h(4)=2

Combined Successors: [4, 5, 3, 4]
Removing Duplicates: [4, 5, 3]
Sorted by Heuristic: [5, 4, 3] (h=0, h=2, h=4)
New Beam: [5, 4] (keep best 2 nodes)
Beam Size: 2
```

### Level 3: Goal Detection
```
Current Beam: [5, 4]
Check Node 5: IS GOAL! ✓
Result: Goal found at node 5
Search Status: SUCCESS
```

## Algorithm Performance

### Nodes Explored
```
Level 0: 1 node  (0)
Level 1: 2 nodes (1, 2)
Level 2: 2 nodes (4, 5)
Total: 5 nodes explored
```

### Optimal Path Found
```
Path: 0 → 2 → 5
Cost: 2 hops
Quality: Optimal (shortest path to goal)
```

## Comparison with Other Algorithms

### Complete Search
```
Nodes Explored: All 6 nodes
Memory Usage: O(n) where n = total nodes
Guarantee: Finds optimal solution
```

### Beam Search (k=2)
```
Nodes Explored: 5 nodes
Memory Usage: O(k) where k = beam width
Guarantee: May find good solution quickly
```

### Greedy Search (k=1)
```
Nodes Explored: 3 nodes (0 → 2 → 5)
Memory Usage: O(1)
Result: Same optimal path (lucky case)
```

## Key Insights

1. **Beam width of 2 was sufficient** for this problem
2. **Heuristic guided search effectively** toward the goal
3. **Memory usage remained constant** at beam width
4. **Solution found quickly** without exploring all nodes
5. **Optimal solution achieved** in this case (not guaranteed)
