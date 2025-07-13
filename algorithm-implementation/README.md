# 🧠 AI Algorithm Implementation Collection

> This repository contains implementations of various artificial intelligence and search algorithms, each with detailed explanations, complexity analysis, applications, and examples.

---

## 🔍 Algorithm Categories

### 🌐 Uninformed Search Algorithms

| Algorithm | Description |
|-----------|-------------|
| [🌳 **Breadth-First Search (BFS)**](BFS/README.md) | Explores all neighbor nodes at the present depth before moving to nodes at the next level |
| [🔍 **Depth-First Search (DFS)**](DFS/README.md) | Explores as far as possible along each branch before backtracking |
| [🔎 **Depth-Limited Search (DLS)**](DLS/README.md) | A variant of DFS with a maximum depth limit to prevent infinite exploration |
| [🔄 **Iterative Deepening Search (IDS)**](Iterative-Deepening-Search/README.md) | Combines benefits of DFS and BFS by running DLS with increasing depth limits |
| [🔀 **Bi-Directional Search**](Bi-Directional%20Search/README.md) | Searches simultaneously from both start and goal states, meeting in the middle |

### 🧭 Informed Search Algorithms

| Algorithm | Description |
|-----------|-------------|
| [🧭 **Best-First Search**](Best-First-Search/README.md) | Uses a heuristic function to determine which node to explore next |
| [🔦 **Beam Search**](Beam-Search/README.md) | Explores a graph by expanding only the most promising nodes at each level |

### ♟️ Game Tree Algorithms

| Algorithm | Description |
|-----------|-------------|
| [♟️ **Minimax**](Min-Max/README.md) | Finds the optimal move in two-player zero-sum games |
| [♟️ **Alpha-Beta Pruning**](Alpha-Beta-Prunning/README.md) | Optimizes Minimax by eliminating branches that cannot influence the final decision |

### 🏔️ Optimization Algorithms

| Algorithm | Description |
|-----------|-------------|
| [🏔️ **Hill Climbing**](Hill-Climb/README.md) | Local search that moves in the direction of increasing value to find the peak |

---

## 📁 Repository Structure

Each algorithm folder contains:

1. **Source Code Implementation**: Working code in C++ or Python
2. **Comprehensive README** with:
   - 🔧 Detailed explanation of how the algorithm works
   - 🚀 Real-world applications of the algorithm
   - ⏱️ Time and space complexity analysis with best, average, and worst cases
   - 📊 References to input/output examples (images in i-o-images folder)

---

## 💻 Usage Instructions

To run any algorithm:

1. Navigate to the specific algorithm folder
2. Compile and run the source code according to its language:
   - For C++: `g++ filename.cpp -o output && ./output`
   - For Python: `python filename.py`
3. Follow the input prompts or modify the code for your specific use case

---

## 🤝 Contributing

Contributions are welcome! To add new algorithms or improve existing implementations:

1. Fork the repository
2. Create a new branch for your feature
3. Add your implementation following the established structure
4. Submit a pull request

---

## 📚 Learning Resources

These implementations are designed to be educational. For further study on AI algorithms:
- Artificial Intelligence: A Modern Approach by Russell and Norvig
- Introduction to Algorithms by Cormen, Leiserson, Rivest, and Stein
- MIT OpenCourseWare: Artificial Intelligence
