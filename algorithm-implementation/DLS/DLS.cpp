#include <bits/stdc++.h>
using namespace std;

// ************************************************
// Constants & Global Variables Declaration
// ************************************************
const int N = 1e5 + 10;   // Maximum number of nodes

bool visited[N];          // visited[] keeps track of visited nodes to prevent re-visits
vector<int> g[N];         // Adjacency list for the graph (undirected)
int target, maxDepth;     // The node we're trying to find & the max search depth
bool found = false;       // Flag to know if the target has been found early

// ************************************************
// Function: dfs
// Purpose: Perform a depth-limited DFS from node `v`
// Parameters:
// - v: current node being visited
// - depth: current depth of DFS call
// ************************************************
void dfs(int v, int depth)
{
    // Base Case 1: If depth exceeds allowed max depth OR target is already found
    if (depth > maxDepth || found)
        return;

    // Mark current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Base Case 2: If current node is the target, mark as found and stop
    if (v == target)
    {
        found = true;
        return;
    }

    // Recursive Case: Visit all unvisited neighbors (children)
    for (int child : g[v])
    {
        if (visited[child])
            continue; // Skip if already visited to prevent cycles

        dfs(child, depth + 1); // Recurse deeper, increase depth by 1
    }
}

int main()
{
    int v, e; // v = number of vertices, e = number of edges
    cin >> v >> e;

    // *****************************
    // Input edges to build the graph
    // It's undirected, so we add edges both ways
    // *****************************
    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;

        g[n1].push_back(n2); // Connect n1 → n2
        g[n2].push_back(n1); // Connect n2 → n1 since undirected
    }

    int start;
    cin >> start >> target >> maxDepth;

    // *****************************
    // Start Depth-Limited DFS from the starting node
    // *****************************
    dfs(start, 0); // Begin DFS from start at depth 0

    // *****************************
    // Output whether target was found within maxDepth
    // *****************************
    if (found)
        cout << "\nTarget found\n";
    else
        cout << "\nTarget not found within depth\n";
}