#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool BFS(int V, vector<int> adj[], int u, vector<int>& color, int c){
        
        color[u] = c;
        queue<int> q;
        
        q.push(u);
        
        while(!q.empty()){
            int v = q.front();
            q.pop();
            
            for(auto w : adj[v]){
                
                if(color[w] == -1){
                    color[w] = 1-color[v];
                    q.push(w);
                }
                else if(color[w] == color[v]) return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	   
	   vector<int> color(V, -1);
	   
	   for(int i = 0; i<V; i++)
	   if(color[i] == -1 && !BFS(V, adj, i, color, 1))
	   return false;
	   
	   return true;
	    
	    
	}
	

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
