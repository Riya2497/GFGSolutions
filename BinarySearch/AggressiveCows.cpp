#include <iostream>

using namespace std;

bool check(vector<int>& stalls, int minDist, int c){
    
    int i, cows, lsat_pos;
    
    start = stalls[0];
    
    cows = 1;
    
    for(i=1; i<n; i++){
        
        if(stalls[i]-last_pos >= minDist){
            cows++;
            last_pos = stalls[i];
            if(cows == c) return true;
        }
    }
    return false;
}

int findminDist(vector<int>& stalls, int c){
    
    int lo, hi, n, best;
    
    n = stalls.size();
    hi = stalls[n-1];
    best = 0;
    
    while(lo <= hi){
        
        mid = lo+(hi-lo)/2;
        
        if(check(stalls, mid, c)){
            lo = mid+1;
            best = mid;
        }
        else hi = mid-1;
    }
    return pos;
}

int main()
{
   int t;
   cin>>t;
   
   while(t--){
       
       int n, c, i;
       
       cin>>n;
       cin>>c;
       
       vector<int> stalls(n, 0);
       
       i = 0;
       
       while(n--){
           cin>>stalls[i];
           i++;
       }
       
       sort(stalls.begin(), stalls.end());
       
       cout<< findMinDist(stalls, c);
   }
   
   return 0;
}
