#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> next_smaller(vector<int>& ip,int n){
    
    stack<int> stk;
    vector<int> ans(n, -1);
    
    int i;
    stk.push(0);
    
    for(i=1; i<n; i++){
        
        if(ip[i] < ip[stk.top()]){
            
            while(!stk.empty() && (ip[i] < ip[stk.top()])){
                ans[stk.top()] = ip[i];
                stk.pop();
            }
            
        }
        stk.push(i);
    }
    return ans;
    
}
int main() {
	int n, i, val;
	vector<int> ip;
	cin>>n;
	
	for(i = 0; i<n; i++){
	   cin>>val;
	   ip.push_back(val);
	}
	
	vector<int> ans = next_smaller(ip, n);
	
	for(i=0; i<n; i++)cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
