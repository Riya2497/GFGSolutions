#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    
		    int arr[26] = {0};
		    queue<char> q;
		    
		    string op;
		    
		    for(int i = 0; i<A.size(); i++){
		        
		        arr[A[i] - 'a']++;
		        
		        q.push(A[i]);
		        
		        while(!q.empty()){
		            
		            if(arr[q.front() - 'a'] > 1) q.pop();
		            else break;
		        }
		        
		        if(q.empty()) op += '#';
		        else op += q.front();
		        
		    }
		    return op;
		}
		
		

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
