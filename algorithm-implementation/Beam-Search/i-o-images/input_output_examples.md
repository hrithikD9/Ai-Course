# Input/Output Examples for Beam Search

## Example 1: Simple Path Finding

### Input
```
Enter number of nodes and edges: 6 8
Enter heuristic values:
10 8 6 4 2 0
Enter edges (u v):
0 1
0 2
1 3
1 4
2 4
2 5
3 5
4 5
Enter start, goal, and beam width: 0 5 2
```

### Graph Visualization
```
      0 (h=10)
     ╱ ╲
    1   2 (h=8, h=6)
   ╱│   │╲
  3 4   4 5 (h=4, h=2, h=2, h=0)
  │╱    │╱
  5     5 (h=0) ← GOAL
```

### Expected Output
```
Goal found at node 5
```

### Execution Path
```
Step 1: Start at node 0
Step 2: Expand to nodes [1, 2], keep [2, 1] (best 2)
Step 3: Expand to nodes [4, 5, 3, 4], keep [5, 4] (best 2)
Step 4: Goal found at node 5
```

---

## Example 2: Narrow Beam Search

### Input
```
Enter number of nodes and edges: 5 6
Enter heuristic values:
8 6 4 2 0
Enter edges (u v):
0 1
0 2
1 3
2 3
3 4
1 4
Enter start, goal, and beam width: 0 4 1
```

### Graph Visualization
```
    0 (h=8)
   ╱ ╲
  1   2 (h=6, h=4)
  │╲ ╱│
  │ ╲ ╱│
  4   3 (h=0, h=2)
     ╱
    4 (h=0) ← GOAL
```

### Expected Output
```
Goal found at node 4
```

### Execution Path (Greedy)
```
Step 1: Start at node 0
Step 2: Expand to nodes [1, 2], keep [2] (beam width = 1)
Step 3: Expand to nodes [3], keep [3]
Step 4: Expand to nodes [4], keep [4]
Step 5: Goal found at node 4
```

---

## Example 3: Goal Not Found

### Input
```
Enter number of nodes and edges: 4 3
Enter heuristic values:
5 3 1 0
Enter edges (u v):
0 1
1 2
0 3
Enter start, goal, and beam width: 0 2 1
```

### Graph Visualization
```
    0 (h=5)
   ╱ ╲
  1   3 (h=3, h=0)
  │   
  2 (h=1) ← GOAL
```

### Expected Output
```
Goal not found within beam width.
```

### Execution Path
```
Step 1: Start at node 0
Step 2: Expand to nodes [1, 3], keep [3] (best heuristic = 0)
Step 3: Node 3 has no successors, search terminates
Step 4: Goal 2 was never reached due to beam width limitation
```

---

## Example 4: Optimal Path vs Beam Search

### Input
```
Enter number of nodes and edges: 5 5
Enter heuristic values:
4 1 3 2 0
Enter edges (u v):
0 1
0 2
1 4
2 3
3 4
Enter start, goal, and beam width: 0 4 1
```

### Graph Visualization
```
    0 (h=4)
   ╱ ╲
  1   2 (h=1, h=3)
  │   │
  │   3 (h=2)
  │  ╱
  4 ╱  (h=0) ← GOAL
```

### Expected Output
```
Goal found at node 4
```

### Analysis
```
Optimal Path: 0 → 1 → 4 (2 steps)
Beam Search Path: 0 → 1 → 4 (2 steps)
Result: Optimal solution found (lucky case)

If heuristic was misleading:
Bad Heuristic: h(1)=5, h(2)=1
Then: 0 → 2 → 3 → 4 (3 steps, suboptimal)
```

---

## Example 5: Large Beam Width

### Input
```
Enter number of nodes and edges: 7 9
Enter heuristic values:
6 5 4 3 2 1 0
Enter edges (u v):
0 1
0 2
1 3
1 4
2 4
2 5
3 6
4 6
5 6
Enter start, goal, and beam width: 0 6 4
```

### Graph Visualization
```
       0 (h=6)
      ╱ ╲
     1   2 (h=5, h=4)
    ╱│   │╲
   3 4   4 5 (h=3, h=2, h=2, h=1)
   │╱    │╱
   6     6 (h=0) ← GOAL
```

### Expected Output
```
Goal found at node 6
```

### Execution Path
```
Step 1: Start at node 0
Step 2: Expand to [1, 2], keep [2, 1] (beam width = 4, keep both)
Step 3: Expand to [4, 5, 3, 4], keep [5, 4, 3] (best 3, beam width allows)
Step 4: Expand to [6, 6, 6], keep [6] (goal found)
```

---

## Performance Comparison

### Nodes Explored by Algorithm

| Example | Complete BFS | Beam (k=1) | Beam (k=2) | Beam (k=∞) |
|---------|-------------|------------|------------|------------|
| Ex 1    | 6 nodes     | 3 nodes    | 5 nodes    | 6 nodes    |
| Ex 2    | 5 nodes     | 4 nodes    | 5 nodes    | 5 nodes    |
| Ex 3    | 4 nodes     | 2 nodes    | 4 nodes    | 4 nodes    |
| Ex 4    | 5 nodes     | 3 nodes    | 4 nodes    | 5 nodes    |
| Ex 5    | 7 nodes     | 4 nodes    | 6 nodes    | 7 nodes    |

### Memory Usage

| Beam Width | Max Memory | Description |
|------------|------------|-------------|
| k = 1      | O(b)       | Greedy search memory |
| k = 2      | O(2b)      | Small beam memory |
| k = 4      | O(4b)      | Medium beam memory |
| k = ∞      | O(b^d)     | Complete search memory |

Where b = average branching factor, d = depth

---

## Key Takeaways

1. **Beam width controls the trade-off** between speed and solution quality
2. **Heuristic quality significantly impacts** search effectiveness
3. **Small beam widths risk missing solutions** but are very fast
4. **Large beam widths approach complete search** but use more memory
5. **Algorithm is particularly effective** when good heuristics are available
