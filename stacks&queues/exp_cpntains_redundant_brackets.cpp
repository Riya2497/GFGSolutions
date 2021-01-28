#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool redundant(string str){
    
    stack<int> stk;
    int i;
    
    for(i=0; i<str.size(); i++){
        
        if(str[i] == ')'){
            
            char ch = stk.top();
            stk.pop();
            bool flag = true;
            while(ch != '('){
                
                if(ch == '*' || ch == '+' || ch == '/' || ch == '-') flag = false;
                
                ch = stk.top();
                stk.pop();
            }
            if(flag == true) return true;
        }
        else stk.push(str[i]);
    }
    return false;
}

int main(){
    
    string str;
    cin>>str;
    if(redundant(str)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}
