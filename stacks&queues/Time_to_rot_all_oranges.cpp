#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        queue<pair<int, int>> q;
        int i, j, count;
        bool flag ;
        for(i=0; i<grid.size(); i++){
            for(j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2) q.push(make_pair(i,j));
            }
        }
        count = 0;
        while(!q.empty()){
            int size = q.size();
            flag = false;
            while(size--){
                pair<int, int> temp = q.front();
                q.pop();
            
                int x = temp.first;
                int y = temp.second;
                
                if((x-1)>=0 && grid[x-1][y]==1){
                    grid[x-1][y] = 2;
                    q.push(make_pair(x-1, y));
                    flag = true;
                }
                if((x+1)<grid.size() && grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    q.push(make_pair(x+1,y));
                    flag = true;
                }
                if((y-1)>=0 && grid[x][y-1] == 1){
                    grid[x][y-1] = 2;
                    q.push(make_pair(x, y-1));
                    flag = true;
                }
                if((y+1)<grid[0].size() && grid[x][y+1] == 1){
                    grid[x][y+1] = 2;
                    q.push(make_pair(x, y+1));
                    flag = true;
                }
            }
            if(flag == true) count++;
        }
        for(i=0; i<grid.size(); i++){
            for(j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        
        return count;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
