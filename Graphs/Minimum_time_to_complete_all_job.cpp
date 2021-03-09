#include <iostream>
#include<map>
#include<vector>
#include <queue>
using namespace std;

void printOrder(int n, map<int, vector<int>> adj){
    
    vector<int> job(n+1,0);
    vector<int> indegree(n+1, 0);
    int i;
    for(i = 1; i<=n; i++){
        
        for(auto j : adj[i]) indegree[j]++;
    }
    
    queue<int> q;
    for(i=1; i<=n; i++){
        
        if(indegree[i] == 0){
            q.push(i);
            job[i] = 1;
        }
    }
    
    while(!q.empty()){
        
        int curr = q.front();
        q.pop();
        
        for(auto j : adj[curr]){
            
            indegree[j]--;
            if(indegree[j] == 0){
                q.push(j);
                job[j] = job[curr]+1;
            }
        }
    }
    
    for(i = 1; i<=n; i++){
        cout<<job[i]<<" ";
    }
}
int main() {
	map<int, vector<int>> adj;
	int n = 10;
	int m = 13;
	
	
	adj[1].push_back(3);
	adj[1].push_back(4);
	adj[1].push_back(5);
	adj[2].push_back(3);
	adj[2].push_back(8);
	adj[2].push_back(9);
	adj[3].push_back(6);
	adj[4].push_back(6);
	adj[4].push_back(8);
	adj[5].push_back(8);
	adj[6].push_back(7);
	adj[7].push_back(8);
	adj[8].push_back(10);
	
	printOrder(n, adj);
	
	return 0;
}
