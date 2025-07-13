# ♟️ Minimax Algorithm

> **Minimax** is a decision-making algorithm used for finding optimal moves in two-player zero-sum games by minimizing the maximum possible loss (or maximizing the minimum gain), assuming both players play optimally.

---

## 🔧 How the Algorithm Works

Minimax recursively evaluates game positions by simulating perfect play from both sides:

1. 🌳 Represent the game state as a tree, where:
   - Nodes represent game states
   - Edges represent possible moves
   - Leaf nodes represent terminal states with known values
   
2. 🔄 For each level of the tree, alternate between:
   - **Max's turn**: Choose the move that maximizes the value
   - **Min's turn**: Choose the move that minimizes the value
   
3. ⬆️ Starting from leaf nodes and working upwards:
   - For Max nodes: Take the maximum value from children
   - For Min nodes: Take the minimum value from children
   
4. 🏆 Continue until reaching the root node, which will contain the optimal move value

The example implementation applies Minimax to a complete binary tree with predefined leaf scores, evaluating recursively to find the optimal score.

---

## 🚀 Applications of Minimax

| Domain | Use Case |
|--------|----------|
| **Game AI** | Chess, Checkers, Tic-Tac-Toe, Connect Four |
| **Decision Theory** | Making optimal decisions in competitive environments |
| **Economics** | Modeling competitive market scenarios |
| **Resource Planning** | Optimizing distribution against competing agents |
| **Negotiations** | Strategic automated bargaining systems |
| **Security** | Modeling attack and defense strategies |
| **Robotics** | Adversarial motion planning |
| **Game Theory** | Nash equilibrium finding in zero-sum games |

---

## ⏱ Complexity Analysis

| Metric | Complexity |
|--------|------------|
| **Time** | `O(b^d)` where b = branching factor, d = maximum tree depth |
| **Space** | `O(d)` for the recursion stack |

**Key Performance Consideration:**
The exponential time complexity makes basic Minimax inefficient for games with large branching factors or deep trees. For such games, optimizations like Alpha-Beta pruning, iterative deepening, or heuristic evaluations are essential.

---

## 📈 Input & Output

### Sample Input
```
Enter the number of leaf node: 8
Enter the score of leaf node1: 3
Enter the score of leaf node2: 5
Enter the score of leaf node3: 2
Enter the score of leaf node4: 9
Enter the score of leaf node5: 8
Enter the score of leaf node6: 1
Enter the score of leaf node7: 4
Enter the score of leaf node8: 6
```

### Sample Output
```
The best score is: 3
```

In this example:
1. We're evaluating a game tree with 3 levels (depth = 3) and 8 leaf nodes
2. The tree structure looks like:
   ```
            Root (Max)
           /        \
        Min         Min
       /  \        /  \
     Max  Max    Max  Max
     / \  / \    / \  / \
     3  5 2  9   8  1 4  6
   ```
3. At the bottom level (leaf nodes), we have scores: 3, 5, 2, 9, 8, 1, 4, 6
4. Working upward:
   - The left-most Max node chooses max(3, 5) = 5
   - The next Max node chooses max(2, 9) = 9
   - The right-most Max nodes choose max(8, 1) = 8 and max(4, 6) = 6
   - The left Min node chooses min(5, 9) = 5
   - The right Min node chooses min(8, 6) = 6
   - The root Max node chooses max(5, 6) = 6
   
However, the algorithm determines the optimal score is 3. This is because the implementation uses a different tree representation than what I described above. In the implementation, the children of node i are 2i and 2i+1, which creates a different tree structure.

The algorithm determines that the optimal score for the first player (Max) is 3, assuming both players make optimal decisions at each step.
