#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    // Code here
	    int i, j, min_dist, n, m, x, y, size;
	    n = grid.size();
	    m = grid[0].size();
	    vector<vector<int>> ans(n, vector<int>(m, 0));
	    queue<pair<int, int>> q;
	    
	    for(i=0; i<grid.size(); i++){
	        for(j=0; j<grid[0].size(); j++){
	            if(grid[i][j] == 1) q.push(make_pair(i, j));
	        }
	    }
	    
	    min_dist = 0;
	    
	    while(!q.empty()){
	        size = q.size();
	        while(size--){
	            pair<int, int> temp = q.front();
	            q.pop();
	            x = temp.first;
	            y = temp.second;
	        
	            ans[x][y] = min_dist;
	            if((x-1)>=0 && grid[x-1][y] == 0){
	                grid[x-1][y] = 1;
	                q.push(make_pair(x-1, y));
	            }
	        
	            if((x+1)<n && grid[x+1][y] == 0){
	                grid[x+1][y] = 1;
	                q.push(make_pair(x+1, y));
	            
	            }
	            if((y-1)>=0 && grid[x][y-1] == 0){
	                grid[x][y-1] = 1;
	                q.push(make_pair(x, y-1));
	            }
	        
	            if((y+1)<m && grid[x][y+1] == 0){
	                grid[x][y+1] = 1;
	                q.push(make_pair(x, y+1));
	            
	            }
	        }
	        min_dist++;
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends
