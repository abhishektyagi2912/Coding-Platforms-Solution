#include <bits/stdc++.h> 
int findSetBit(int n) {   
    // Write your code here
    if(n==0) return -1;
    if((n & (n-1)) == 0){
        int ans = 0;
        while(n){
            ans++;
            n = n>>1;
        }
        return ans;
    }
    else return -1;
}

