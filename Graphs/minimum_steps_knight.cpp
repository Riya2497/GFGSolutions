#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    struct cell{
        int x,y,dist;
    };
    bool isValid(int x, int y, int N){
        if(x >=1 && y>=1 && x<=N && y<=N ) return true;
        else return false;
    }
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    int steps = 0;
	    queue<cell> q;
	    int xpos[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
        int ypos[] = { -1, -2, -2, -1, 1, 2, 2, 1 };  
	    int cx, cy, dx, dy;
	    cx = KnightPos[0];
	    cy = KnightPos[1];
	    dx = TargetPos[0];
	    dy = TargetPos[1];
	    
	    int visit[N + 1][N + 1]; 
  
        for(int i = 1; i <= N; i++) 
            for (int j = 1; j <= N; j++) 
                visit[i][j] = 0;
	    
	    q.push({cx, cy, 0});
	    
	    while(!q.empty()){
	        
	        cell temp = q.front();
	        q.pop();
	        int a = temp.x;
	        int b = temp.y;
	        if(temp.x == dx && temp.y == dy) return temp.dist;
	       
	        for(int i=0; i<8; i++){
	            if(isValid(a+xpos[i], b+ypos[i], N)){
	                if(visit[a+xpos[i]][b+ypos[i]] == 0){
	                    visit[a+xpos[i]][b+ypos[i]]= 1;
	                    q.push({a+xpos[i], b+ypos[i], temp.dist+1});
	                }
	            }
	        }
	        
	        
	    }
	    
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
