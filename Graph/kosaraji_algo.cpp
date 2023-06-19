#include<bits/stdc++.h>

using namespace std;

void DFS(int node , vector<int> adj[] , stack<int> &st , vector<int> &visited_array ){
    visited_array[node] = 1;
    
    for(auto it:adj[node]){
        if(!visited_array[it])
          DFS(it , adj , st , visited_array);
    }
    st.push(node);
}
void DFS3(int node , vector<int> &visited_array , vector<int> adjT[]){
    visited_array[node] = 1;
    for(auto it:adjT[node]){
        if(!visited_array[it])
          DFS3(it , visited_array , adjT);
    }
}

int kosaraju(int V , vector<int> adj[]){
   vector<int> visited_array(V, 0);
   stack<int> st ;
   
   for(int i = 0 ; i< V ; i++){
     if(!visited_array[i]){
        DFS(i , adj , st , visited_array);
     }
   }

   //step 2 : reverse the graph
   vector<int> adjT[V];
   for(int i = 0 ; i < V ;i++){
      for(auto it:adj[i]){
        adjT[it].push_back(i);
      }
   }

   //step 3 : Do the Dfs 
   int ssc = 0 ;
   vector<int> v_a(V, 0);
   while(!st.empty()){
    int node = st.top();
    st.pop();
    if(!v_a[node]){
       ssc++;
       DFS3(node , v_a ,adjT );
    }
   }
   return ssc;
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

   cout<<kosaraju(n , adj);

    return 0;
}