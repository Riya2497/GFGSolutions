
 // } Driver Code Ends
class Solution {
public:
    bool DFS(int i, vector<int> &visited, vector<int>adj[], int parent){
        
        visited[i] = 1;
        for(auto u : adj[i]){
            if(visited[u] == 0){
                if(DFS(u, visited, adj, i))
                    return true;
            }
            else if(u != parent){
                return true;
            }
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[]){
	    // Code here
	    vector<int> visited(V, 0);
	    return DFS(0, visited, adj, -1);
	    
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
