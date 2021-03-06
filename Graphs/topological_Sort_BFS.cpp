#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	void topo(int i,int V, int vis[],vector<int> adj[], stack<int> &s)
    {
        vis[i]=1;
        for(int j =0 ;j<adj[i].size();j++)
        {
            if(!vis[adj[i][j]])
            topo(adj[i][j],V,vis,adj,s);
        }
        s.push(i);
    }
vector<int> topoSort(int V, vector<int> adj[]) {
    
    vector<int> indegree(V, 0);
    
    for(int i=0; i<V; i++){
        
        for(int j = 0;j<adj[i].size(); j++){
            indegree[adj[i][j]]++;
        }
    }
    queue<int> q;
    vector<int> ans;
    
    for(int i=0; i<V; i++){
        
        if(indegree[i] == 0) q.push(i);
    }
    
    while(!q.empty()){
        
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(int j = 0; j<adj[curr].size(); j++){
            indegree[adj[curr][j]]--;
            if(indegree[adj[curr][j]] == 0) q.push(adj[curr][j]);
            
        }
    }
    return ans;
}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
