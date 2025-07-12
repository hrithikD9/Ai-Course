# Alpha-Beta Pruning Execution Trace

## Initial State
```
Root(0) - MAX
α = -1000, β = 1000
```

## Step-by-Step Execution

### Level 1: Exploring Node 1 (MIN)
```
Node 1 (MIN) - α=-1000, β=1000
├── Child 4 (MAX)
│   ├── Child 10 → Leaf values: 5, 6 → returns 6
│   └── Child 11 → Leaf values: 7, 4, 5 → returns 7
│   └── Node 4 returns max(6, 7) = 7
├── Child 5 (MAX)
│   └── Child 12 → Leaf value: 3 → returns 3
│   └── Node 5 returns 3
└── Node 1 returns min(7, 3) = 3
```

### Level 1: Exploring Node 2 (MIN)
```
Node 2 (MIN) - α=3, β=1000
├── Child 6 (MAX)
│   ├── Child 13 → Leaf value: 6 → returns 6
│   └── Child 14 → Leaf values: 6, 9 → returns 9
│   └── Node 6 returns max(6, 9) = 9
├── Child 7 (MAX)
│   └── Child 15 → Leaf value: 7 → returns 7
│   └── Node 7 returns 7
└── Node 2 returns min(9, 7) = 7
```

### Level 1: Exploring Node 3 (MIN)
```
Node 3 (MIN) - α=3, β=1000
├── Child 8 (MAX)
│   └── Child 16 → Leaf value: 5 → returns 5
│   └── Node 8 returns 5
├── Child 9 (MAX)
│   ├── Child 17 → Leaf values: 9, 8 → returns 9
│   └── Child 18 → Leaf value: 6 → returns 6
│   └── Node 9 returns max(9, 6) = 9
└── Node 3 returns min(5, 9) = 5
```

### Final Result
```
Root(0) - MAX
└── Returns max(3, 7, 5) = 7
```

## Output
```
Optimal value using Alpha-Beta Pruning: 7
```

## Pruning Analysis

**Nodes Evaluated**: 33 nodes (no pruning occurred in this specific tree)
**Optimal Path**: Root → Node 2 → Node 6 → Node 14 → Leaf 27 (value 9)

*Note: The actual output depends on the specific tree structure and traversal order in the implementation.*
