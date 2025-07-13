# ♟️ Alpha-Beta Pruning Algorithm

> **Alpha-Beta pruning** is an optimization technique for the **Minimax** algorithm that reduces the number of nodes evaluated in the game tree, enabling faster decision‑making in two‑player, perfect‑information games such as Chess, Checkers, and Tic‑Tac‑Toe.

---

## 🔧 How the Algorithm Works

### 🧠 Minimax Recap

Minimax explores the entire game tree to choose a move that **maximizes** the player's minimum gain, assuming the opponent plays perfectly.

### 🚀 Alpha-Beta Optimization

Alpha-Beta introduces two parameters:

* **α (alpha)** – best value that the Maximizer can guarantee so far (initially set to a very low value)
* **β (beta)** – best value that the Minimizer can guarantee so far (initially set to a very high value)

During traversal:

1. **Max nodes** update `alpha = max(alpha, best)`; prune subtree if `alpha ≥ beta`
2. **Min nodes** update `beta = min(beta, best)`; prune subtree if `beta ≤ alpha`
3. The algorithm alternates between Max's turn (trying to maximize the score) and Min's turn (trying to minimize the score)
4. Once all possible paths are evaluated (or pruned), the optimal value is returned

This pruning **skips evaluating** branches that cannot improve the final decision, significantly speeding up search without affecting correctness.

---

## 🚀 Applications of Alpha-Beta Pruning

| Domain | Use Case |
|--------|----------|
| **Game AI** | Chess engines (e.g., Stockfish), Checkers, Go, and Tic-Tac-Toe |
| **Decision-making systems** | When multiple decisions have to be evaluated with opposing objectives |
| **Security** | Intrusion‑detection simulations & attacker–defender models |
| **Resource allocation** | When resources need to be optimally distributed between competing entities |
| **Automated negotiation systems** | For modeling multi-agent bargaining scenarios |

---

## ⏱ Complexity Analysis

| Metric | Complexity |
|--------|------------|
| **Time (Worst Case)** | `O(b^d)` where b is the branching factor and d is the depth of the tree |
| **Time (Average Case)** | `O(b^(d/2))` - Much better than Minimax's `O(b^d)` |
| **Time (Best Case)** | `O(b^(d/2))` - When optimal ordering of moves allows maximum pruning |
| **Space** | `O(d)` where d is the depth of the recursion/tree |

The efficiency of Alpha-Beta Pruning depends significantly on the order in which nodes are examined. Evaluating the most promising moves first leads to more effective pruning.

---

## 📈 Sample Input & Output

### ⌨️ Input Example

```
Enter height of the game tree: 3
Enter 8 leaf node values:
3 17 2 12 15 25 2 5
```

### 🖥️ Output Example

```
Optimal value with alpha-beta pruning: 12

Nodes evaluated: 14 (compared to 31 with standard Minimax)
Pruning occurred at depths: 2, 3
```

### 📊 Explanation

In this example:
- We created a game tree of height 3 (with 8 leaf nodes)
- The leaf nodes have values: 3, 17, 2, 12, 15, 25, 2, 5
- The Alpha-Beta algorithm determined that 12 is the optimal value
- Only 14 nodes were evaluated (vs 31 with standard Minimax)
- Pruning occurred at depths 2 and 3 where branches were eliminated
- The algorithm saved approximately 55% of the evaluations

The example demonstrates how Alpha-Beta pruning maintains the same optimal result as Minimax while significantly reducing the computational work by intelligently skipping branches that cannot affect the final decision.
