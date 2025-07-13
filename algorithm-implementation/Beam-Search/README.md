# 🔦 Beam Search Algorithm

> **Beam Search** is a heuristic search algorithm that explores a graph by expanding only the most promising nodes at each level, balancing efficiency and solution quality through a configurable "beam width" parameter.

---

## 🔧 How the Algorithm Works

Beam Search optimizes search by keeping only the best candidates at each step:

1. 🏁 Start with an initial state (the starting node)
2. 🌟 At each level of the search:
   - Generate all successor states from the current states
   - Evaluate each successor using a heuristic function
   - Select the best k states (where k is the beam width)
   - Discard all other states
3. 🔄 Continue until the goal state is found or the search terminates
4. ⚠️ If the goal is not found within beam constraints, report failure

The key parameter in beam search is the **beam width (k)**, which controls the trade-off between:
- 🚀 Smaller width: More efficient but may miss optimal solutions
- 🔍 Larger width: More thorough but computationally expensive

---

## 🚀 Applications of Beam Search

| Domain | Use Case |
|--------|----------|
| **Machine Translation** | Selecting promising partial translations |
| **Speech Recognition** | Pruning unlikely word sequences |
| **Computer Vision** | Image captioning, object recognition |
| **Bioinformatics** | Protein structure prediction |
| **Robotics** | Path planning in autonomous systems |
| **NLP** | Text generation, sentence completion |
| **Compiler Design** | Finding efficient instruction sequences |
| **AI Systems** | Various search problems with large branching factors |

---

## ⏱ Complexity Analysis

| Metric | Complexity |
|--------|------------|
| **Time** | `O(b·w)` per level, where b = branching factor, w = beam width |
| **Space** | `O(w)` where w = beam width |

**Key Performance Notes:**
- Unlike BFS with `O(b^d)` space complexity at maximum width, beam search keeps space bounded by the beam width
- Makes beam search practical for problems with very large branching factors
- Trade-off between optimality and efficiency is controlled by beam width

---

## 📈 Sample Input & Output

### ⌨️ Input Example

```
Enter number of nodes and edges: 8 10
Enter heuristic values:
12 9 7 5 6 4 2 0
Enter edges (u v):
0 1
0 2
1 3
1 4
2 4
2 5
3 6
4 6
4 7
5 7
Enter start, goal, and beam width: 0 7 2
```

### 🖥️ Output Example

```
Exploring level 1:
  Generated nodes: 1, 2
  Selected for beam: 2, 1 (best heuristic values: 7, 9)
Exploring level 2:
  Generated nodes: 4, 5
  Selected for beam: 5, 4 (best heuristic values: 4, 6)
Exploring level 3:
  Generated nodes: 7, 6
  Selected for beam: 7, 6 (best heuristic values: 0, 2)
Goal found at node 7
Path: 0 → 2 → 5 → 7
```

### 📊 Explanation

In this example:
- We have a graph with 8 nodes (0-7) with heuristic values
- Node 0 is the start, node 7 is the goal
- Beam width is set to 2 (only keep 2 best nodes at each level)
- At level 1, nodes 1 and 2 are generated, both kept in the beam
- At level 2, nodes 4 and 5 are explored (from nodes 1 and 2)
- At level 3, nodes 6 and 7 are explored, with node 7 being the goal

The beam search successfully found the path 0 → 2 → 5 → 7 by focusing only on the most promising nodes at each level. With a smaller beam width, the search is more efficient but might miss optimal solutions if promising paths are prematurely discarded.
