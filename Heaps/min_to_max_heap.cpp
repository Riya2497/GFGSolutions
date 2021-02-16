#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int>& A, int i){
    
    int largest = i;
    int left = (2*i) + 1;
    int right = (2*i) + 2;
    
    if(left < A.size() && A[left] > A[largest]) largest = left;
    if(right < A.size() && A[right] > A[largest]) largest = right;
    
    if(largest != i){
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxHeapify(A, largest);
    }
    
}
void min_to_max_heap(vector<int> &A){
    
    int i , n;
    n = A.size();
    for(i = (n-2)/2; i>=0; i--) maxHeapify(A, i);
    
    for(i=0; i<A.size(); i++) cout<<A[i]<<" ";
    cout<<endl;
}
int main() {
	int n, i;
	cin>>n;
	vector<int> A(n, 0);
	for(i=0; i<n; i++) cin>>A[i];
	
	min_to_max_heap(A);
	return 0;
}
