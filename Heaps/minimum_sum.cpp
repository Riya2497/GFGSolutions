//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution{   
public:
    void max_heapify(int arr[], int i, int n){
        
        int largest = i;
        int left = (2*i) + 1;
        int right = (2*i) + 2;
        
        if(left < n && arr[left] > arr[largest]) largest = left;
        if(right < n && arr[right] > arr[largest]) largest = right;
        
        if(largest != i){
            int temp = arr[largest];
            arr[largest] = arr[i];
            arr[i] = temp;
            max_heapify(arr, largest, n);
        }
    }
    void heapSort(int arr[], int n){
        
        int i;
        for(i=(n/2)-1; i>=0; i--) max_heapify(arr, i, n);
        
        i = n-1;
        while(i){
            
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            max_heapify(arr, 0, i);
            i--;
        }
        
    }
    string minSum(string s1, string s2){
        
        int a, b, carry, i, j, sum, temp;
        string op = "";
        
        carry = 0;
        i = s1.size()-1;
        j = s2.size()-1;
        //cout<<s1<<endl;
        //cout<<s2<<endl;
        
        while(i >= 0 || j >= 0){
            temp = 0;
            if(i >= 0){
                temp += (s1[i] - '0');
                i--;
            }
            if(j >= 0){
                temp += (s2[j] - '0');
                j--;
            }
            if(carry) temp += carry;
            op += to_string(temp%10);
            //cout<<op<<endl;
            
            carry = temp/10;
            
        }
        
        if(carry){
            op += to_string(carry);
        }
        reverse(op.begin(), op.end());
        i = 0;
        while(i < op.size() && op[i] == '0') i++;
        return op.substr(i);
        
    }
    string solve(int arr[], int n) {
        // code here
        heapSort(arr, n);
        
        int i;
        string s1 = "";
        string s2 = "";
        i = 0;
        while(i < n){
            
            if(i %2 == 0){
                s1 += to_string(arr[i]);
                
            }
            else{
                s2 += to_string(arr[i]);
            }
            i++;
        }
        return minSum(s1, s2);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
