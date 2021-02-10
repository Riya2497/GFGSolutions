#include<bits/stdc++.h>


#define N 105
using namespace std;

int *mergeKArrays(int arr[][N],int k);

void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}// } Driver Code Ends


// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
struct Node{
    int val, i, j;
    Node(int v, int ipos, int jpos){
        val = v;
        ipos = i;
        jpos = j;
    }
};

struct mycompare{
    bool operator()(Node& a, Node& b){
        return a.val > b.val;
    }
};
typedef pair<int, pair<int, int>> p;
int *mergeKArrays(int arr[][N], int k)
{
//code her
    priority_queue<p, vector<p>, greater<p>> pq;
    int *ans = new int[k*k];
    int i, j;
    
    for(i=0; i<k; i++) pq.push(make_pair(arr[i][0], make_pair(i, 0)));
    
    j = 0;
    while(!pq.empty()){
        
        p temp = pq.top();
        pq.pop();
        ans[j++] = temp.first;
        
        int ipos = temp.second.first;
        int jpos = temp.second.second;
        
        if((jpos+1) < k){
            pq.push(make_pair(arr[ipos][jpos+1], make_pair(ipos, jpos+1)));
        }
    }
    
    return ans;
}
