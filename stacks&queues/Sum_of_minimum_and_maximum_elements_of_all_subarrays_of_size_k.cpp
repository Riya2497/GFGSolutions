#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void find_min_max_sum(vector<int> &vec, int n, int k){
    
    deque<int> S, G;
    int i, sum;
    sum = 0;
    
    for(i=0; i<k; i++){
        while(!S.empty() && vec[i] <= vec[S.back()])S.pop_back();
        
        while(!G.empty() && vec[i] >= vec[G.back()]) G.pop_back();
        
        S.push_back(i);
        G.push_back(i);
    }
    
    for(i = k; i<n; i++){
        
        sum += vec[S.front()]+vec[G.front()];
        
        while(!S.empty() && S.front()<=i-k)S.pop_front();
        while(!G.empty() && G.front()<=i-k) G.pop_front();
        
        while(!S.empty() && vec[i] <= vec[S.back()])S.pop_back();
        
        while(!G.empty() && vec[i] >= vec[G.back()]) G.pop_back();
        
        S.push_back(i);
        G.push_back(i);
    }
    sum += vec[S.front()] + vec[G.front()];
    cout<<sum<<endl;
}
int main() {
	
	int i, n, val, k;
	cin>>n;
	
	vector<int> vec;
	
	for(i=0; i<n; i++){
	    cin>>val;
	    vec.push_back(val);
	}
	cin>>k;
	
	find_min_max_sum(vec, n, k);
	
	return 0;
}
