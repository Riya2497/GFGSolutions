#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void insert_bottom(int x, stack<int>& stk){
    if(stk.size() == 0)stk.push(x);
    
    else{
        
        int val = stk.top();
        stk.pop();
        insert_bottom(x, stk);
        stk.push(val);
    }

}
void reverse(stack<int>& stk){
    
    if(stk.size() == 1) return;
    
    int val = stk.top();
    stk.pop();
    reverse(stk);
    insert_bottom(val, stk);
}
void interleave(queue<int>& q){
    
    stack<int> stk;
    
    if(q.size() % 2 != 0){
        printf("Not possible\n");
        return;
    }
    
    int i, n;
    n = q.size();
    for(i=1; i<=n/2; i++){
        stk.push(q.front());
        q.pop();
    }
    reverse(stk);
    
    while(!stk.empty()){
        q.push(stk.top());
        stk.pop();
        q.push(q.front());
        q.pop();
    }
}
int main() {
	queue<int> q;
	
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	interleave(q);
	
	while(!q.empty()){
	    cout<<q.front()<<endl;
	    q.pop();
	}
	return 0;
}
