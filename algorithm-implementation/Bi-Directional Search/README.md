# 🔀 Bi-Directional Search Algorithm

> **Bi-Directional Search** is a graph search algorithm that runs two simultaneous searches—one forward from the source and one backward from the goal—meeting in the middle for dramatically faster pathfinding in large graphs.

---

## 🔧 How the Algorithm Works

Bi-Directional Search simultaneously explores from both ends to meet in the middle:

1. 🏁 Initialize two searches:
   - Forward search starting from the source node
   - Backward search starting from the goal node
2. 🔄 Alternate between the two searches, expanding one layer at a time from each direction
3. 🔍 After each expansion step, check if the two searches have intersected
4. 🔗 When an intersection is found, construct the complete path by combining:
   - The path from source to the meeting point
   - The path from the meeting point to the goal (reversed)
5. ❌ If either search exhausts all possible nodes without finding an intersection, no path exists

This approach is most effective when both the source and goal nodes are known in advance, and the branching factor is large.

---

## 🚀 Applications of Bi-Directional Search

| Domain | Use Case |
|--------|----------|
| **Navigation** | Route planning in road networks and transportation systems |
| **Networking** | Finding efficient routes in computer networks |
| **Game Development** | Pathfinding in large game worlds |
| **Social Networks** | Finding shortest connections between people |
| **Robotics** | Motion planning through complex environments |
| **Electronic Design** | Finding connections between components in circuits |
| **Database Systems** | Optimizing certain types of relational queries |
| **AI Planning** | Finding optimal action sequences in planning problems |

---

## ⏱ Complexity Analysis

| Metric | Complexity |
|--------|------------|
| **Time** | `O(b^(d/2))` where b = branching factor, d = shortest path length |
| **Space** | `O(b^(d/2))` for storing frontier nodes in both directions |

**Key Performance Advantage:**
- b^(d/2) + b^(d/2) is much smaller than b^d for large d
- Provides exponential speedup over traditional unidirectional search
- Effectively reduces the depth of the search by half
- Dramatic improvement for problems with large branching factors

---

## 📈 Input & Output

### Sample Input
```
Enter the number of vertices: 8
Enter the number of edges: 10
Enter the edges (vertex1 vertex2):
0 1
0 2
1 3
1 4
2 5
2 6
3 7
4 7
5 7
6 7
Enter the starting vertex: 0
Enter the target vertex: 7
```

### Sample Output
```
Target vertex found!
Path: 0 1 3 7
```

The algorithm runs two simultaneous searches:
- Forward search from vertex 0 (start)
- Backward search from vertex 7 (target)

When the two searches meet (at vertex 3 in this example), the complete path is reconstructed by:
1. Combining the path from start to meeting point (0 → 1 → 3)
2. And the path from meeting point to target (3 → 7)

This demonstrates how Bi-Directional Search efficiently finds paths by exploring from both ends simultaneously, dramatically reducing the search space compared to traditional unidirectional search methods.
