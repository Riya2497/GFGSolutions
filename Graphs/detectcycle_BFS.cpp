#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    struct Node{
        int v, parent;
    };
	bool isCycle(int V, vector<int>adj[]){
	    // Code here
	    vector<int> visited(V,0);
	    
	    queue<Node> q;
	    q.push({0,-1});
	    visited[0] = 1;
	    
	    while(!q.empty()){
	        Node temp = q.front();
	        q.pop();
	        
	        for(auto u : adj[temp.v]){
	            
	            if(visited[u] == 0){
	                visited[u] = 1;
	                q.push({u, temp.v});
	                
	            }
	            else if(u != temp.parent) return true;
	        }
	    }
	    
	    return false;
	    
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
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
