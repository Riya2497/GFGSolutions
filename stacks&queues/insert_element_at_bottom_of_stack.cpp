#include <iostream>
#include <stack>
using namespace std;

void insertBottom(int x, stack<int>& stk){
    
    if(stk.empty()) stk.push(x);
    
    else{
        int val = stk.top();
        stk.pop();
        insertBottom(x,stk);
        stk.push(val);
    }
}
void reverse(stack<int>& stk){
    
    if(stk.empty()) return;
    
    int val = stk.top();
    stk.pop();
    reverse(stk);
    
    insertBottom(val, stk);
}

int main() {
	//code
	stack<int> stk;
	
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);
	stk.push(5);
	
	reverse(stk);
	while(!stk.empty()){
	    cout<<stk.top();
	    stk.pop();
	}
	return 0;
}
