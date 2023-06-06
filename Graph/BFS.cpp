#include <bits/stdc++.h>
using namespace std;

vector<int> Bfs(int n, vector<int> adj[]) {
    int visited_array[n + 1] = {0}; // Increase size to n+1

    queue<int> list;
    list.push(1); // Start from node 1 (1th index )

    visited_array[1] = 1; // Start from node 1 (1th index)
  
    vector<int> mylist;

    while (!list.empty()) {
        int node = list.front();
        list.pop();
        mylist.push_back(node);

        for (auto it : adj[node]) {
         /* adjoint vector r sob value r joono visited array te check korteche .
         jodi visited array te kono nirdisto number r jonno 1 thake thats means already visited . 
        visited na hole q te push korte hobe */
            if (!visited_array[it]) {
                visited_array[it] = 1;
                list.push(it); // Corrected line
            }
        }
    }
    return mylist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> result = Bfs(6, adj);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}
