# Tree Structure Visualization

## Complete Tree Structure (33 Nodes)

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
```

## Leaf Node Values

```
Node 19: 5    Node 24: 3    Node 29: 5
Node 20: 6    Node 25: 6    Node 30: 9
Node 21: 7    Node 26: 6    Node 31: 8
Node 22: 4    Node 27: 9    Node 32: 6
Node 23: 5    Node 28: 7
```

## Alpha-Beta Pruning Execution

```
Step 1: Start at Root(0) - MAX, α=-1000, β=1000
├── Explore Node 1 (MIN)
│   ├── Explore Node 4 (MAX)
│   │   ├── Explore Node 10 → returns 5 (from leaves 19,20)
│   │   └── Explore Node 11 → returns 4 (from leaves 21,22,23)
│   │   └── Node 4 returns max(5,4) = 5
│   ├── Explore Node 5 (MAX)
│   │   └── Explore Node 12 → returns 3 (from leaf 24)
│   │   └── Node 5 returns 3
│   └── Node 1 returns min(5,3) = 3, α=3
├── Explore Node 2 (MIN)
│   ├── Explore Node 6 (MAX) → returns 6
│   ├── Explore Node 7 (MAX) → returns 7
│   └── Node 2 returns min(6,7) = 6
├── Explore Node 3 (MIN)
│   ├── Explore Node 8 (MAX) → returns 5
│   ├── Explore Node 9 (MAX) → returns 8
│   └── Node 3 returns min(5,8) = 5
└── Root returns max(3,6,5) = 6

Final Result: 6
```

## Pruning Opportunities

When β ≤ α, we can prune remaining branches:
- Saves computational time
- Reduces nodes evaluated
- Maintains optimal solution
