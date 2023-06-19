#include<iostream> 
#include<vector>
#include<queue>
using namespace std ;

vector<int> BFS(int n , vector<int> adj[]){
    int visited_array[n+1] = {0};
    queue<int> list ;
    visited_array[1] = 1;
    list.push(1); 
    vector<int> mylist;

    while(!list.empty()){
        int node = list.front();
        list.pop();
        mylist.push_back(node);

        for(auto it:adj[node]){
            
            if(!visited_array[it])
              visited_array[it] = 1;
            list.push(it);
        }
    }

    return mylist;

}


int main(){
    int n , m ;
    cin>>n>>m;
    
    vector <int> adj[n+1] ;

    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin>> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
        
    } 

    vector<int> result = BFS(n , adj);
    
     for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}