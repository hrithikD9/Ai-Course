# 🏔️ Hill Climbing Algorithm

> **Hill Climbing** is a local search optimization algorithm that finds maxima or minima by always moving in the direction of increasing or decreasing value, like a hiker always stepping in the steepest uphill direction.

---

## 🔧 How the Algorithm Works

Hill Climbing follows a simple "always improve" approach:

1. 🏁 Start with an initial candidate solution
2. 📊 Evaluate the current solution using an objective function
3. 🔄 Generate a neighboring solution (typically by making a small change)
4. ⬆️ If the neighbor is better than the current solution, move to that solution
5. 🔁 Repeat steps 2-4 until no better neighbor can be found or maximum iterations reached
6. 🏆 Return the best solution found

In the example implementation, the algorithm maximizes a quadratic function f(x) = -x² + 10x (which has its maximum at x = 5), starting at a user-specified point and moving in fixed steps until no further improvement can be made.

---

## 🚀 Applications of Hill Climbing

| Domain | Use Case |
|--------|----------|
| **Optimization** | Finding local maxima/minima of functions |
| **Machine Learning** | Training models like neural networks |
| **Operations Research** | Job scheduling, task allocation |
| **Computer Vision** | Image segmentation, feature matching |
| **Electronic Design** | Circuit component placement and routing |
| **Navigation** | Local route planning and optimization |
| **Game AI** | Simple decision-making algorithms |
| **Logistics** | Local optimization of delivery routes |

---

## ⏱ Complexity Analysis

| Metric | Complexity |
|--------|------------|
| **Time** | `O(n)` worst case where n = search space size |
|         | `O(i)` typical case where i = iterations to peak |
| **Space** | `O(1)` (constant space) |

**Key Performance Characteristics:**
- Extremely memory efficient (stores only current state)
- Often quickly finds a local optimum
- May terminate early without exploring full search space

**Limitations:**
- Can get stuck in local optima rather than finding the global optimum
- Doesn't work well on plateaus (flat areas) or ridges
- Result depends heavily on the starting point

---

## 📈 Input & Output

### Sample Input
```
Enter starting value of x: 0
Enter step size: 1
Enter maximum number of iterations: 10
```

### Sample Output
```
Iteration 1: x = 0, f(x) = 0
Iteration 2: x = 1, f(x) = 9
Iteration 3: x = 2, f(x) = 16
Iteration 4: x = 3, f(x) = 21
Iteration 5: x = 4, f(x) = 24
Iteration 6: x = 5, f(x) = 25
Hill Climbing stopped at x = 5 with value f(x) = 25
```

In this example:
1. We're trying to maximize the function `f(x) = -x² + 10x` which has its maximum at `x = 5`
2. Starting from `x = 0`, the algorithm takes steps of size 1
3. At each iteration, the value of the function increases until reaching `x = 5`
4. At `x = 5`, the function reaches its maximum value of 25
5. If we tried to move to `x = 6`, the function would decrease to 24, so the algorithm stops

This demonstrates how Hill Climbing always moves in the direction of improvement until it reaches a point where no neighbor offers a better solution.
