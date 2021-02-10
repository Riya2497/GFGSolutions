#include <iostream>
#include <vector>
using namespace std;

void max_heapify(vector<int>& A, int i, int n){
    
    int left = 2*i+1;
    int right = 2*i + 2;
    int largest = i;
    
    if(left < n && A[left] > A[largest]) largest = left;
    
    if(right < n && A[right] > A[largest] ) largest = right;
    
    if(largest != i){
        int temp = A[largest];
        A[largest] = A[i];
        A[i] = temp;
        max_heapify(A, largest, n);
    }
}
void buildheap(vector<int>& A, int n){
    int i;
    for(i = (n/2)-1; i>=0; i--){
        max_heapify(A, i, n);
    }
}
int main() {
	int n, i;
	
	cin>>n;
	vector<int> A(n, 0);
	
	for(i=0; i<n ; i++) cin>>A[i];
	
	buildheap(A, n);
	
	for(i=0 ; i<n; i++) cout<<A[i]<<" ";
	cout<<endl;
	return 0;
}
