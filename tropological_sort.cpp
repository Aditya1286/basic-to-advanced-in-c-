#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topologicalSort_Kahn(int V, vector<int> adj[]) {
    vector<int> inDegree(V, 0);
    queue<int> q;
    vector<int> topoOrder;

    // Step 1: Compute in-degree of each node
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }

    // Step 2: Enqueue nodes with 0 in-degree
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: Process nodes from the queue
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Step 4: Check if topological sorting is possible
    if (topoOrder.size() == V) {
        cout << "Topological Sort (Kahn's Algorithm): ";
        for (int node : topoOrder) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "Graph contains a cycle! Topological sorting not possible.\n";
    }
}

int main() {
    int V = 6; // Number of vertices
    vector<int> adj[V];

    // Graph edges (Directed)
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    topologicalSort_Kahn(V, adj);

    return 0;
}
