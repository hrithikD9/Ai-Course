# Beam Search Algorithm Walkthrough

## Visual Algorithm Explanation

### Core Concept
Beam Search maintains a "beam" of the most promising nodes at each level, using a heuristic to guide the search.

```
Traditional Search:        Beam Search (k=2):
     Start                      Start
    /  |  \                    /  |  \
   A   B   C                  A   B   C
  /|\ /|\ /|\                ↓ sort ↓
 ... ... ...                  B   C  (keep best 2)
                              /|\ /|\
                             ... ...
```

## Algorithm Flow Diagram

```
┌─────────────────┐
│  Initialize     │
│  Beam = [start] │
└─────────┬───────┘
          │
          ▼
┌─────────────────┐
│  Expand All     │
│  Nodes in Beam  │
└─────────┬───────┘
          │
          ▼
┌─────────────────┐
│  Collect All    │
│  Successors     │
└─────────┬───────┘
          │
          ▼
┌─────────────────┐
│  Sort by        │
│  Heuristic      │
└─────────┬───────┘
          │
          ▼
┌─────────────────┐
│  Keep Best k    │
│  Nodes          │
└─────────┬───────┘
          │
          ▼
┌─────────────────┐
│  Goal Found?    │
│  Yes → Success  │
│  No → Continue  │
└─────────┬───────┘
          │
          ▼
      (Loop Back)
```

## Detailed Example: 6-Node Graph

### Initial Setup
```
Graph:
  0 ─┐
 ╱   ╲
1     2
│╲   ╱│
│ ╲ ╱ │
3  4  5

Heuristics: h(0)=10, h(1)=8, h(2)=6, h(3)=4, h(4)=2, h(5)=0
Goal: Node 5
Beam Width: 2
```

### Level-by-Level Execution

#### Level 0: Starting Point
```
Beam: [0]
Status: Initialize with start node
```

#### Level 1: First Expansion
```
Expand Node 0:
├── Successors: [1, 2]
├── Heuristics: h(1)=8, h(2)=6
├── Sorted: [2, 1] (lower heuristic = better)
└── New Beam: [2, 1] (both fit in beam width=2)
```

#### Level 2: Second Expansion
```
Expand Node 2:
├── Successors: [4, 5]
├── Heuristics: h(4)=2, h(5)=0

Expand Node 1:
├── Successors: [3, 4]
├── Heuristics: h(3)=4, h(4)=2

Combined & Sorted: [5, 4, 3] (h=0, h=2, h=4)
New Beam: [5, 4] (keep best 2)
```

#### Level 3: Goal Achievement
```
Check Node 5: GOAL FOUND! ✓
Result: Success
Path: 0 → 2 → 5
```

## Beam Width Impact Analysis

### Beam Width = 1 (Greedy)
```
Level 0: [0]
Level 1: [2] (only best node)
Level 2: [5] (only best node)
Result: Found goal (optimal in this case)
```

### Beam Width = 2 (Our Example)
```
Level 0: [0]
Level 1: [2, 1] (top 2 nodes)
Level 2: [5, 4] (top 2 nodes)
Result: Found goal (optimal)
```

### Beam Width = ∞ (Complete Search)
```
Level 0: [0]
Level 1: [2, 1] (all nodes)
Level 2: [5, 4, 3] (all nodes)
Result: Found goal (guaranteed optimal)
```

## Key Algorithm Properties

### Memory Usage Pattern
```
Time Step 1: Store k nodes
Time Step 2: Store k nodes
Time Step 3: Store k nodes
...
Maximum Memory: O(k × largest_successor_count)
```

### Completeness Analysis
```
Complete Algorithm: Always finds solution if it exists
Beam Search: May miss solution if beam width too small
Example: If beam width = 1 and best heuristic leads to dead end
```

### Optimality Analysis
```
Optimal Algorithm: Always finds best solution
Beam Search: May find suboptimal solution
Trade-off: Speed vs. Solution Quality
```

## Practical Considerations

### Choosing Beam Width
```
Small k (1-3):
├── Pros: Fast, memory efficient
└── Cons: May miss good solutions

Medium k (4-10):
├── Pros: Good balance
└── Cons: Moderate resource usage

Large k (10+):
├── Pros: Better solution quality
└── Cons: Higher memory/time cost
```

### Heuristic Function Design
```
Good Heuristic:
├── Admissible: Never overestimates
├── Consistent: Satisfies triangle inequality
└── Informative: Provides good guidance

Poor Heuristic:
├── Misleading: Points away from goal
├── Uninformative: All nodes same value
└── Inconsistent: Violates triangle inequality
```

## Real-World Applications

### Machine Translation
```
Beam Search in Neural Machine Translation:
├── Input: Source sentence
├── Beam: Top k translation candidates
├── Heuristic: Language model probability
└── Output: Best translation sequence
```

### Speech Recognition
```
Beam Search in Speech-to-Text:
├── Input: Audio signal
├── Beam: Top k word sequences
├── Heuristic: Acoustic + language model scores
└── Output: Most likely word sequence
```
