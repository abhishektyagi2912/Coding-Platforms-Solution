class Solution {
public:
    int solve(string& s,int i, int j, vector<vector<int>>& dp){
        //base case
        if(i>j) return 0;
        if(i==j) return 1;

        // dp ko check kro 
        if(dp[i][j] != 0) return dp[i][j];

        int ans =0;
        if(s[i]==s[j]) dp[i][j] = 2+solve(s,i+1,j-1,dp);
        else dp[i][j] = max(solve(s,i+1,j,dp),solve(s,i,j-1,dp));

        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        return solve(s,0,n-1,dp);
    }
};
