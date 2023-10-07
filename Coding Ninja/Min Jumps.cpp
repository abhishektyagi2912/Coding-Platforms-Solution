#include <bits/stdc++.h> 
int solve(int n,int m, vector<vector<int>>&arr, vector<vector<int>>&dp){
  if(n==0 && m == 0){
    return 0;
  }
  if(n<0 || m<0) return 1e8;

  if(dp[n][m]!=-1){
    return dp[n][m];
  }
  int a = 1e8;
  int b = 1e8;
  int c = 1e8;

  if(n>0) a = abs(arr[n][m]-arr[n-1][m]) + solve(n-1,m,arr,dp); 
  if(m>0) b = abs(arr[n][m]-arr[n][m-1]) + solve(n,m-1,arr,dp); 
  if(n>0&&m>0) c = abs(arr[n][m]-arr[n-1][m-1]) + solve(n-1,m-1,arr,dp); 

  return dp[n][m] = min({a,b,c});
}
int findMinCost(vector<vector<int>> arr, int n, int m) {
  // Write your code here.
  vector<vector<int>> dp(n,vector<int>(m,-1));
  return solve(n-1,m-1,arr,dp);
}
