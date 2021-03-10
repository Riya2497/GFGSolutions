
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    int getMin(int a, int b){
        
        return (a > b) ? b : a;
    }
	void shortest_distance(vector<vector<int>>&A){
	    // Code here
	    
	    int i, j, k, n;
	    
	    n = A.size();
	    
	    for(k=0; k<n; k++){
	        
	        for(i=0; i<n; i++){
	            
	            for(j = 0; j<n; j++){
	                
	                A[i][j] = getMin(A[i][j], A[i][k]+A[k][j]);
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
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends
