class Solution {
public:
    int solve(vector<int>& v, vector<vector<int>>& dp, int i, int j){
        // only two points are their
        if(i+1 == j) return 0; 
        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for(int k = i+1; k<j; k++){
            ans = min(ans, v[i]*v[j]*v[k] + solve(v,dp,i,k) + solve(v,dp,k,j));
            dp[i][j] = ans;
        }
        return dp[i][j];
    }
    //nc3-n if n>5
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(values,dp,0,n-1);
    }
};
