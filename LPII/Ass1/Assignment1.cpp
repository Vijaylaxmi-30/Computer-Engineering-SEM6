#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/* -------- DFS Recursive -------- */
void DFS_Recursive(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int next : adj[node]) {
        if (!visited[next]) {
            DFS_Recursive(next, adj, visited);
        }
    }
}

/* -------- DFS Iterative -------- */
void DFS_Iterative(int start, vector<vector<int>> &adj, int V) {
    vector<bool> visited(V, false);
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            for (int next : adj[node]) {
                if (!visited[next]) {
                    st.push(next);
                }
            }
        }
    }
}

/* -------- BFS Iterative -------- */
void BFS_Iterative(int start, vector<vector<int>> &adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int next : adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

/* -------- BFS Recursive -------- */
void BFS_Helper(queue<int> &q, vector<vector<int>> &adj, vector<bool> &visited) {
    if (q.empty()) return;

    int node = q.front();
    q.pop();
    cout << node << " ";

    for (int next : adj[node]) {
        if (!visited[next]) {
            visited[next] = true;
            q.push(next);
        }
    }

    BFS_Helper(q, adj, visited);
}

void BFS_Recursive(int start, vector<vector<int>> &adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    BFS_Helper(q, adj, visited);
}

/* -------- MAIN -------- */
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // undirected graph
    }

    int choice, start;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. DFS Recursive\n";
        cout << "2. DFS Iterative\n";
        cout << "3. BFS Iterative\n";
        cout << "4. BFS Recursive\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter starting vertex: ";
            cin >> start;
        }

        switch (choice) {
            case 1: {
                vector<bool> visited(V, false);
                cout << "DFS Recursive: ";
                DFS_Recursive(start, adj, visited);
                cout << endl;
                break;
            }
            case 2:
                cout << "DFS Iterative: ";
                DFS_Iterative(start, adj, V);
                cout << endl;
                break;

            case 3:
                cout << "BFS Iterative: ";
                BFS_Iterative(start, adj, V);
                cout << endl;
                break;

            case 4:
                cout << "BFS Recursive: ";
                BFS_Recursive(start, adj, V);
                cout << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}