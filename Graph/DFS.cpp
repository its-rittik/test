#include<bits/stdc++.h>

using namespace std ;

void dfs_recursion(int start , vector<int> adj[] , int visited_array[] , vector<int> &ls){
     
      ls.push_back(start);
     visited_array[start] = 1 ; //alredy pushed in list so mark as 1 
    

     for(auto it:adj[start]){
          if(!visited_array[it]){
             visited_array[it] = 1;
              dfs_recursion(it , adj , visited_array , ls);
          }
     }
}


vector<int> DFS (int start ,int n , vector<int> adj[]){
     
     int visited_array[n+1] = {0} ; //if 0th base then visited_array[n]
    
     vector<int> ls;

      dfs_recursion(start ,adj , visited_array , ls);
     return ls;
}

int main() {
    int n, m;
    cout<<"Total numver of vartex: ";
    cin >> n ;
    cout<<"Total number of edge: ";
    cin>>m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"From which node you want to traverse: ";
    int x ;
    cin>>x;
    vector<int> result = DFS(x, n, adj);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}