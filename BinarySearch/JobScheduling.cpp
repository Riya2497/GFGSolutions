#include <iostream>
#include <algorithm>
using namespace std;
struct Job
{
    int start, finish, profit;
};
bool jobComparator(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}

int findNonConflict(Job arr[], int i){
    
    for(int j = i-1; j>=0; j--){
        
        if(arr[j].finish <= arr[i-1].start) return j;
    }
    return -1;
}
int findMaxProfitRecur(Job arr[], int n){
    
    if(n == 1) return arr[n-1].profit;
    
    int incl = arr[n-1].profit;
    int i = findNonConflict(arr, n);
    if(i != -1) incl += findMaxProfitRecur(arr, i+1);
    
    int excl= findMaxProfitRecur(arr, n-1);
    
    return max(incl, excl);
}
int findMaxProfit(Job arr[], int n){
    
    sort(arr, arr+n, jobComparator);
    
    return findMaxProfitRecur(arr, n);
}
int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The optimal profit is " << findMaxProfit(arr, n);
    return 0;
   
}
