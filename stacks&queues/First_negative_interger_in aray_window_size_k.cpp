#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	
	while(t--){
	    
	    int n, i, val, k, x;
	    cin>>n;
	    
	    vector<int> arr;
	    queue<int> q;
	    
	    for(i=0; i<n; i++){
	        cin>>val;
	        arr.push_back(val);
	    }
	    cin>>k;
	    
	    for(i=0; i<k; i++){
	        q.push(arr[i]);
	    }
	    for(i=k-1; i<n; i++){
	        while(!q.empty() && q.front()>0) q.pop();
	        if(q.empty()) cout<<"0"<<" ";
	        else cout<<q.front()<<" ";
	        if(q.size() == k) q.pop();
	        
	        if(i+1 < n) q.push(arr[i+1]);
	        
	    }
	    cout<<endl;
	    
	}
	return 0;
}
