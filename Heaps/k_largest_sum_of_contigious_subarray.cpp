#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	
	int n, i, j,k;
	cin>>n;
	cin>>k;
	vector<int> A(n);
	
	for(i=0; i<n; i++) cin>>A[i];
	
	vector<int> sum(n+1);
	sum[0] = 0;
	sum[1] = A[0];
	
	for(i=1; i<=n; i++) sum[i] = sum[i-1] + A[i-1];
	
	priority_queue<int, vector<int>, greater<int>> pq;
	
	//pq.push(sum[1]);
	
	for(i=1; i<=n; i++){
	    
	    for(j = 0; j<i; j++){
	        int x = sum[i] - sum[j];
	        if(pq.size() < k) pq.push(x);
	        
	        else{
	            if(pq.top() < x){
	                pq.pop();
	                pq.push(x);
	            }
	        }
	    }
	}
	cout<<endl;
	cout<<pq.top();

	return 0;
}
