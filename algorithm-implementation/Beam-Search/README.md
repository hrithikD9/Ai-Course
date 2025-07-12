# 🔍 Beam Search Algorithm

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

**Beam Search** is a heuristic search algorithm that explores a graph by expanding the most promising nodes in a limited set. It's an optimization of **Best-First Search** that uses a fixed-size beam width to limit memory usage and computational complexity.

Key characteristics:
- **Incomplete**: May not find a solution even if one exists
- **Not Optimal**: May not find the best solution
- **Memory Efficient**: Uses limited memory (beam width)
- **Fast**: Explores fewer nodes than complete search algorithms

The algorithm maintains a "beam" of the most promising nodes at each level, determined by a heuristic function.

---

## ⚙️ How the Algorithm Works

### 🔄 Algorithm Steps

1. **Initialize**: Start with the initial node in the beam
2. **Expand**: Generate all successors of nodes in the current beam
3. **Evaluate**: Score all successors using a heuristic function
4. **Select**: Keep only the best k nodes (where k = beam width)
5. **Repeat**: Continue until goal is found or beam becomes empty

### 🎯 Key Concepts

```
Level 0: [Start Node]
           ↓ (expand)
Level 1: [All Successors] → Sort by heuristic → Keep best k
           ↓ (expand)
Level 2: [All Successors] → Sort by heuristic → Keep best k
           ↓ (repeat)
```

### 📊 Beam Width Impact

```
Beam Width = 1: → Greedy Best-First Search
Beam Width = ∞: → Complete Best-First Search
Beam Width = k: → Balanced trade-off
```

---

## 🎮 Applications

### 🏆 Primary Applications

1. **Natural Language Processing**
   - 🗣️ Speech recognition systems
   - 🔤 Machine translation
   - 📝 Text generation and parsing
   - 🤖 Chatbot response generation

2. **Computer Vision**
   - 🖼️ Image recognition
   - 🎯 Object detection
   - 📱 Optical Character Recognition (OCR)
   - 🎬 Video analysis

3. **Artificial Intelligence**
   - 🎯 Pathfinding in games
   - 🧠 Neural network training
   - 🔍 Search space optimization
   - 🤖 Robotics navigation

4. **Optimization Problems**
   - 📊 Scheduling systems
   - 🚚 Route optimization
   - 💰 Resource allocation
   - 📈 Portfolio optimization

### 🌟 Real-World Examples

- **Google Translate**: Uses beam search for sequence-to-sequence translation
- **Speech Recognition**: Apple Siri, Google Assistant use beam search
- **Chess Engines**: Some use beam search for move pruning
- **Autonomous Vehicles**: Path planning with limited computation

---

## 📈 Time & Space Complexity

### ⏱️ Time Complexity

| Metric | Complexity | Description |
|--------|------------|-------------|
| **Per Level** | O(b × k × log k) | b = branching factor, k = beam width |
| **Total** | O(d × b × k × log k) | d = depth of solution |
| **Sorting** | O(n log n) | n = number of nodes at current level |

### 💾 Space Complexity

| Component | Complexity | Description |
|-----------|------------|-------------|
| **Beam Storage** | O(k) | Stores beam width nodes |
| **Next Level** | O(b × k) | Temporary storage for expansion |
| **Total** | O(b × k) | Maximum space used |

### 🚀 Performance Comparison

```
Complete Search vs Beam Search (k=3):
├── Complete: Explores all b^d nodes
├── Beam Search: Explores ≤ k×d nodes
└── Speedup: Exponential reduction in nodes explored
```

---

## 🔧 Implementation Details

### 📝 Core Algorithm Structure

```cpp
// Main search loop
while (!beam.empty()) {
    // 1. Expand all nodes in current beam
    vector<int> next_level;
    for (each node in beam) {
        add all successors to next_level;
    }
    
    // 2. Sort by heuristic (best first)
    sort(next_level, heuristic_comparator);
    
    // 3. Keep only best k nodes
    beam = top k nodes from next_level;
    
    // 4. Check for goal
    if (goal found) return success;
}
```

### 🏗️ Key Components

1. **Heuristic Function**: Evaluates node quality (lower = better)
2. **Beam Management**: Queue to store current beam nodes
3. **Graph Representation**: Adjacency list for efficient traversal
4. **Sorting Mechanism**: Prioritizes nodes by heuristic value

---

## 📸 Input & Output Examples

### 📥 Sample Input

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

### 📤 Sample Output

```
Goal found at node 5
```

### 🎯 Graph Visualization

```
Graph Structure:
       0 (h=10)
      / \
     1   2 (h=8,6)
    /|   |\
   3 4   4 5 (h=4,2,2,0)
   |/    |/
   5     5 (h=0) ← GOAL
```

### 📊 Execution Trace

**Step 1**: Start with node 0
- Beam: [0]
- Heuristic: h(0) = 10

**Step 2**: Expand node 0
- Successors: [1, 2]
- Heuristics: h(1) = 8, h(2) = 6
- Sorted: [2, 1] (lower heuristic first)
- Beam (k=2): [2, 1]

**Step 3**: Expand nodes 2 and 1
- From node 2: successors [4, 5]
- From node 1: successors [3, 4]
- All successors: [4, 5, 3, 4]
- Heuristics: h(4) = 2, h(5) = 0, h(3) = 4
- Sorted: [5, 4, 4, 3]
- Beam (k=2): [5, 4]

**Step 4**: Goal found!
- Node 5 is the goal → Search terminates successfully

---

## 🏗️ Code Structure

### 📦 Key Components

1. **Input Handling**: Reads graph structure and search parameters
2. **Graph Building**: Creates adjacency list representation
3. **Beam Management**: Uses queue for level-by-level processing
4. **Heuristic Sorting**: Lambda function for custom comparison
5. **Goal Detection**: Checks each node as it's processed

### 🔧 Compilation & Execution

```bash
# Compile
g++ -o beam Beam.cpp

# Run
./beam
```

### 🎨 Algorithm Visualization

```
Level 0:     [Start]
             ↓ expand
Level 1:   [All Children] → sort → [Best k]
             ↓ expand
Level 2:   [All Children] → sort → [Best k]
             ↓ expand
Level 3:   [Goal Found!] ✓
```

---

## 💡 Algorithm Characteristics

### ✅ Advantages

- **Memory Efficient**: Fixed memory usage regardless of search space
- **Fast Execution**: Explores fewer nodes than complete search
- **Scalable**: Works well with large search spaces
- **Tunable**: Beam width can be adjusted based on requirements

### ❌ Disadvantages

- **Incomplete**: May miss the optimal solution
- **Not Guaranteed**: May fail to find existing solutions
- **Heuristic Dependent**: Performance heavily relies on heuristic quality
- **Local Optimum**: May get stuck in suboptimal paths

---

## 🎯 Key Parameters

### 🔧 Beam Width Selection

```
Small k (k=1-3):
├── Faster execution
├── Lower memory usage
└── Higher chance of missing optimal solution

Large k (k>10):
├── Better solution quality
├── Higher memory usage
└── Slower execution
```

### 🎨 Heuristic Function Quality

- **Admissible**: Never overestimates the cost to goal
- **Consistent**: Satisfies triangle inequality
- **Informative**: Provides good guidance toward goal

---

## 📚 Related Algorithms

- **Best-First Search**: Beam search with infinite beam width
- **Greedy Search**: Beam search with beam width = 1
- **A* Search**: Optimal search using f(n) = g(n) + h(n)
- **Breadth-First Search**: Exhaustive level-by-level search

---

## 🔍 Example Use Cases

### 🎮 Game AI
```cpp
// Pathfinding in games
beam_width = 5;  // Balance between speed and accuracy
heuristic = manhattan_distance_to_goal;
```

### 🗣️ Speech Recognition
```cpp
// Word sequence generation
beam_width = 10;  // Keep top 10 word sequences
heuristic = language_model_probability;
```

### 🤖 Machine Translation
```cpp
// Sentence translation
beam_width = 4;   // Common choice in NMT
heuristic = translation_score;
```

---

## 📋 Detailed Visual Examples

For comprehensive step-by-step execution traces and detailed analysis, see:
- [`execution_trace.md`](i-o-images/execution_trace.md) - Complete execution walkthrough with sample data
- [`algorithm_walkthrough.md`](i-o-images/algorithm_walkthrough.md) - Visual algorithm explanation and flow diagrams  
- [`input_output_examples.md`](i-o-images/input_output_examples.md) - Multiple test cases with expected outputs

---

*💡 Beam Search provides an excellent balance between computational efficiency and solution quality, making it invaluable for real-time applications where complete search is impractical.*
