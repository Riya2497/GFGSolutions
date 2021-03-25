
 // } Driver Code Ends
class Solution {
public:
    bool DFS(vector<int>adj[], int V, int u, vector<int>& color, int c){
        
        if(color[u] != -1) return (color[u] == c);
        
        color[u] = c;
        
        for(auto v : adj[u]){
            if(!DFS(adj, V, v, color, 1-c))
                return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    
	    
	    vector<int> color(V,-1);
	    
	    for(int i = 0; i<V; i++)
	        if(color[i]==-1 && !DFS(adj, V, i, color, 1)) 
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
