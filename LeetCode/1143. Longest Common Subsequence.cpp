class Solution {
    int solve(string& a, string& b, int i ,int j, vector<vector<int>>& dp){
        //base case 
        if(i == a.length()) return 0;
        if(j == b.length()) return 0;

        //check if it ans is already present 
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(a[i]==b[j]){
            ans = 1+solve(a,b,i+1,j+1,dp);
        }
        else{
            ans = max(solve(a,b,i+1,j,dp),solve(a,b,i,j+1,dp));
        }
        return dp[i][j] = ans;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp (text1.length(), vector<int>(text2.length(), -1));
        return solve(text1, text2, 0, 0, dp);
    }
};
