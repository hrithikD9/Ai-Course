# 🌳 Alpha-Beta Pruning Algorithm

## 📋 Table of Contents
- [Overview](#overview)
- [How the Algorithm Works](#how-the-algorithm-works)
- [Applications](#applications)
- [Time & Space Complexity](#time--space-complexity)
- [Implementation Details](#implementation-details)
- [Input & Output Examples](#input--output-examples)
- [Code Structure](#code-structure)

---

## 🔍 Overview

Alpha-Beta Pruning is an optimization technique for the **Minimax algorithm** used in two-player zero-sum games. It significantly reduces the number of nodes evaluated in the search tree by eliminating branches that cannot possibly influence the final decision.

The algorithm maintains two values:
- **Alpha (α)**: The best value that the maximizing player can guarantee
- **Beta (β)**: The best value that the minimizing player can guarantee

When `β ≤ α`, the algorithm "prunes" the remaining branches, as they won't affect the optimal decision.

---

## ⚙️ How the Algorithm Works

### 🔄 Algorithm Steps

1. **Initialization**: Start with α = -∞ and β = +∞
2. **Recursive Evaluation**: 
   - For **MAX nodes**: Try to maximize the score, update α
   - For **MIN nodes**: Try to minimize the score, update β
3. **Pruning Condition**: If β ≤ α at any point, prune the remaining children
4. **Leaf Node Evaluation**: Return the static evaluation value

### 🎯 Key Concepts

```
MAX Level: Tries to maximize score
├── Updates α = max(α, current_best)
└── Prunes when β ≤ α

MIN Level: Tries to minimize score  
├── Updates β = min(β, current_best)
└── Prunes when β ≤ α
```

### 📊 Pruning Visualization

```
     MAX (α=-∞, β=+∞)
    /    |    \
   MIN   MIN   MIN
  /|\   /|\   /|\
 5 6 7 4 5 3 6 6 9 ...
```

When exploring left-to-right:
- After evaluating leftmost MIN node → α = 5
- If next MIN node returns value ≤ 5, remaining branches can be pruned

---

## 🎮 Applications

### 🏆 Primary Applications

1. **Game AI Development**
   - ♟️ Chess engines (Stockfish, Deep Blue)
   - 🔴 Checkers/Draughts
   - 🎯 Connect Four
   - 🎲 Tic-Tac-Toe
   - 🀄 Go (with modifications)

2. **Decision Making Systems**
   - 🤖 Autonomous agent planning
   - 📊 Business strategy optimization
   - 🎯 Resource allocation problems

3. **Puzzle Solving**
   - 🧩 Logic puzzles
   - 🔢 Number games
   - 🎪 Strategy-based challenges

### 🌟 Real-World Examples

- **IBM Deep Blue**: Used Alpha-Beta pruning to defeat world chess champion Garry Kasparov
- **Chinook**: Became unbeatable in checkers using optimized Alpha-Beta search
- **Game Development**: Modern game engines use variants for AI opponent behavior

---

## 📈 Time & Space Complexity

### ⏱️ Time Complexity

| Scenario | Without Pruning | With Alpha-Beta Pruning |
|----------|----------------|-------------------------|
| **Worst Case** | O(b^d) | O(b^d) |
| **Best Case** | O(b^d) | O(b^(d/2)) |
| **Average Case** | O(b^d) | O(b^(3d/4)) |

Where:
- **b** = branching factor (number of possible moves)
- **d** = depth of the search tree

### 💾 Space Complexity

- **Space**: O(bd) - due to recursive call stack
- **Additional Storage**: O(1) - only α and β values

### 🚀 Performance Benefits

```
Example: Chess (b≈35, d=10)
├── Without pruning: 35^10 ≈ 2.8 × 10^15 nodes
└── With pruning: 35^5 ≈ 5.2 × 10^7 nodes
    └── Speedup: ~50,000x faster!
```

---

## 🔧 Implementation Details

### 📝 Core Function Parameters

```cpp
int alphaBeta(int nodeIndex, bool isMax, vector<int> &values,
              vector<vector<bool>> &adjMatrix, int n,
              int alpha, int beta)
```

- **nodeIndex**: Current node being processed
- **isMax**: Boolean indicating if it's maximizer's turn
- **values**: Static evaluation values for leaf nodes
- **adjMatrix**: Tree structure representation
- **alpha**: Best score maximizer can guarantee
- **beta**: Best score minimizer can guarantee

### 🏗️ Tree Structure

Our implementation uses a **33-node tree** with:
- **Root**: Node 0 (MAX level)
- **Level 1**: Nodes 1-3 (MIN level)
- **Level 2**: Nodes 4-18 (MAX level)
- **Leaves**: Nodes 19-32 (Terminal values)

---

## 📸 Input & Output Examples

### 📥 Input Tree Structure

```
                    Root(0) - MAX
                   /    |    \
                  1     2     3  - MIN
                 /|\   /|\   /|\
                4 5   6 7   8 9  - MAX
               /| |  /| |  |  |\
             ... ... ... ... ... - LEAVES
```

### 📤 Sample Output

```
Optimal value using Alpha-Beta Pruning: 6
```

### 🎯 Leaf Node Values

| Node | Value | Node | Value | Node | Value |
|------|-------|------|-------|------|-------|
| 19   | 5     | 24   | 3     | 29   | 5     |
| 20   | 6     | 25   | 6     | 30   | 9     |
| 21   | 7     | 26   | 6     | 31   | 8     |
| 22   | 4     | 27   | 9     | 32   | 6     |
| 23   | 5     | 28   | 7     |      |       |

### 📊 Execution Flow

1. **Start**: α = -1000, β = 1000
2. **Traverse**: Depth-first with pruning
3. **Result**: Optimal value = 6

### 🎨 Tree Visualization

```
                             Root(0) - MAX
                            /    |    \
                           1     2     3  - MIN
                          /|\   /|\   /|\
                         4 5   6 7   8 9  - MAX
                        /| |  /| |  |  |\
                      10 11 12 13 14 15 16 17 18 - INTERMEDIATE
                     /| /||\  |  |  |  |  |  |
                   19 20 21 22 23 24 25 26 27 28 29 30 31 32 - LEAVES
                    5  6  7  4  5  3  6  6  9  7  5  9  8  6
```

### 🔍 Input/Output Analysis

**Input Tree Structure:**
- **Total Nodes**: 33 (indexed 0-32)
- **Depth**: 4 levels
- **Branching Factor**: Variable (2-3 children per node)
- **Leaf Nodes**: 14 terminal nodes with static values

**Execution Steps:**
1. **Node 0 (MAX)**: Explores children 1, 2, 3
2. **Node 1 (MIN)**: Returns minimum of its MAX children = 3
3. **Node 2 (MIN)**: Returns minimum of its MAX children = 6  
4. **Node 3 (MIN)**: Returns minimum of its MAX children = 5
5. **Final Result**: max(3, 6, 5) = **6**

**Key Insights:**
- The algorithm explores the tree systematically
- Pruning occurs when β ≤ α condition is met
- Optimal value represents the best possible outcome for the maximizer

### 📋 Detailed Visual Examples

For detailed step-by-step execution traces and tree visualizations, see:
- [`tree_structure.md`](i-o-images/tree_structure.md) - Complete tree structure and node relationships
- [`execution_trace.md`](i-o-images/execution_trace.md) - Step-by-step algorithm execution
- [`algorithm_walkthrough.md`](i-o-images/algorithm_walkthrough.md) - Detailed analysis and walkthrough

---

## 🏗️ Code Structure

### 📦 Key Components

1. **Leaf Detection**: Checks if node has children in adjacency matrix
2. **Maximizer Logic**: Updates α, prunes when β ≤ α
3. **Minimizer Logic**: Updates β, prunes when β ≤ α
4. **Tree Representation**: Uses adjacency matrix for connections

### 🔧 Compilation & Execution

```bash
# Compile
g++ -o alpha_beta alpha_beta_adj.cpp

# Run
./alpha_beta
```

### 🎨 Algorithm Visualization

```
     MAX(α=-∞,β=+∞)
    /              \
   MIN              MIN
  /|\              /|\
 5 6 7            4 5 3
   ^                ^
   |                |
 α=5            β ≤ α → PRUNE!
```

---

## 🎯 Key Advantages

✅ **Efficiency**: Dramatically reduces search space  
✅ **Optimality**: Guarantees same result as Minimax  
✅ **Scalability**: Enables deeper search in reasonable time  
✅ **Memory Efficient**: Minimal additional space requirements  

---

## 📚 Further Reading

- [Minimax Algorithm](https://en.wikipedia.org/wiki/Minimax)
- [Game Tree Search](https://en.wikipedia.org/wiki/Game_tree)
- [Artificial Intelligence: A Modern Approach](http://aima.cs.berkeley.edu/)

---

*💡 This implementation demonstrates the power of Alpha-Beta pruning in reducing computational complexity while maintaining optimal decision-making in adversarial search scenarios.*