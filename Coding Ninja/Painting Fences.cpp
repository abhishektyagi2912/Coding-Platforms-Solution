#include <bits/stdc++.h> 
#define MOD 1000000007
int solve(int n){
    vector<int>dp(n+1,-1);
    dp[1]=2;
    dp[2]=4;
    
    for(int i =3;i<=n;i++){
        dp[i] = (dp[i-1]+dp[i-2])%MOD;
    }
    return dp[n]%MOD;
}
int countWays(int n)
{
    // Write your code here	
    return solve(n);
}
