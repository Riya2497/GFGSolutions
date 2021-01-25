vector<long long> nextLargerElement(vector<long long> arr, int n){
    // Your code here
    stack<long long> s;
    vector<long long> ans;
    int val;
    s.push(-1);
    for(int i=n-2; i>=0; i--){
        if(arr[i+1] > arr[i]) s.push(arr[i+1]);
        else{
            
            stack<long long> s2;
            while(!s.empty() && s.top() < arr[i]){
                s2.push(s.top());
                s.pop();
            }
            if(s.empty()) val = -1;
            else val = s.top();
            while(!s2.empty()){
                s.push(s2.top());
                s2.pop();
            }
            s.push(val);
        }
    }
    
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
