#include <bits/stdc++.h>
using namespace std;

// ******************************************************
// - nodeIndex: current node being processed
// - isMax: if current level is Max's turn, otherwise it's Min's
// - values: vector of all node scores (only leaf nodes have non-zero)
// - adjMatrix: adjacency matrix representing the tree connection
// - n: total number of nodes in the tree
// - alpha: best already explored option for Max so far
// - beta: best already explored option for Min so far
// ******************************************************
int alphaBeta(int nodeIndex, bool isMax, vector<int> &values,
              vector<vector<bool>> &adjMatrix, int n,
              int alpha, int beta)
{
    // *******************************
    // Step 1: Check if node is a leaf
    // If node has no children in adjacency matrix, it's a leaf
    // Return its static value from values[nodeIndex]
    // *******************************
    bool isLeaf = true;
    for (int i = 0; i < n; i++) {
        if (adjMatrix[nodeIndex][i]) {
            isLeaf = false;
            break;
        }
    }
    
    if (isLeaf)
        return values[nodeIndex];

    // ---------------------- Max's Turn ----------------------
    if (isMax) {
        int best = -1000; // Very low initial value for maximizer

        // Go through all children of this node
        for (int i = 0; i < n; i++) {
            if (adjMatrix[nodeIndex][i]) {
                // Recurse: switch to Min's turn
                int val = alphaBeta(i, false, values, adjMatrix, n, alpha, beta);
                best = max(best, val);        // Try to find the best max
                alpha = max(alpha, best);     // Update alpha if we have a better value

                // *** Pruning: if beta <= alpha, stop exploring more children
                if (beta <= alpha)
                    break;
            }
        }
        return best;
    }

    // ---------------------- Min's Turn ----------------------
    else {
        int best = 1000; // Very high initial value for minimizer

        // Go through all children of this node
        for (int i = 0; i < n; i++) {
            if (adjMatrix[nodeIndex][i]) {
                // Recurse: switch to Max's turn
                int val = alphaBeta(i, true, values, adjMatrix, n, alpha, beta);
                best = min(best, val);        // Try to find the minimum
                beta = min(beta, best);       // Update beta if we get a lower value

                // *** Pruning: if beta <= alpha, stop exploring more children
                if (beta <= alpha)
                    break;
            }
        }
        return best;
    }
}

int main()
{
    int n = 33;  // Total number of nodes (0 to 32)
    
    // *******************************
    // Step 1: Initialize node values
    // Only leaf nodes (nodes without children) have values
    // Rest will be calculated by the recursive algorithm
    // *******************************
    vector<int> values(n, 0);  

    // Leaf node values (final game outcomes or heuristic values)
    values[19] = 5;   
    values[20] = 6;   
    values[21] = 7;   
    values[22] = 4;   
    values[23] = 5;   
    values[24] = 3;   
    values[25] = 6;   
    values[26] = 6;   
    values[27] = 9;   
    values[28] = 7;   
    values[29] = 5;   
    values[30] = 9;   
    values[31] = 8;   
    values[32] = 6;   
    
    // *******************************
    // Step 2: Set up the tree using adjacency matrix
    // If adjMatrix[parent][child] = true, it means child is connected to parent
    // This forms the structure of the tree
    // *******************************
    vector<vector<bool>> adjMatrix(n, vector<bool>(n, false));
    
    // Root node connections
    adjMatrix[0][1] = true; adjMatrix[0][2] = true; adjMatrix[0][3] = true;
    
    // Level 1
    adjMatrix[1][4] = true; adjMatrix[1][5] = true;
    adjMatrix[2][6] = true; adjMatrix[2][7] = true;
    adjMatrix[3][8] = true; adjMatrix[3][9] = true;
    
    // Level 2
    adjMatrix[4][10] = true; adjMatrix[4][11] = true;
    adjMatrix[5][12] = true;
    adjMatrix[6][13] = true; adjMatrix[6][14] = true;
    adjMatrix[7][15] = true;
    adjMatrix[8][16] = true;
    adjMatrix[9][17] = true; adjMatrix[9][18] = true;
    
    // Leaves (Level 3)
    adjMatrix[10][19] = true; adjMatrix[10][20] = true;
    adjMatrix[11][21] = true; adjMatrix[11][22] = true; adjMatrix[11][23] = true;
    adjMatrix[12][24] = true;
    adjMatrix[13][25] = true;
    adjMatrix[14][26] = true; adjMatrix[14][27] = true;
    adjMatrix[15][28] = true;
    adjMatrix[16][29] = true;
    adjMatrix[17][30] = true; adjMatrix[17][31] = true;
    adjMatrix[18][32] = true;
    
    // *******************************
    // Step 3: Run Alpha-Beta Algorithm starting from root
    // alpha = best score Max can guarantee so far (start: very low)
    // beta  = best score Min can guarantee so far (start: very high)
    // *******************************
    int alpha = -1000, beta = 1000;

    // Call alphaBeta from root node (index 0), Max’s turn
    int optimalValue = alphaBeta(0, true, values, adjMatrix, n, alpha, beta);
    
    // *******************************
    // Step 4: Output the result
    // This is the optimal score Max can achieve assuming best play
    // *******************************
    cout << "Optimal value using Alpha-Beta Pruning: " << optimalValue << endl;

    return 0;
}