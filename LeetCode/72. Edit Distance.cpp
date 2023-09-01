class Solution {
    int solve(string a, string b, int i, int j, vector<vector<int>>&dp){
        if(i == a.length()) return b.length()-j;
        if(j == b.length()) return a.length()-i;

        if(dp[i][j] != -1) return dp[i][j];

        int ans =0;
        if(a[i]== b[j]){
            return solve(a,b,i+1,j+1,dp);
        }
        else{
            // insertion
            int ins = 1+solve(a,b,i+1,j,dp);
            //dlt
            int dlt = 1+solve(a,b,i,j+1,dp);
            // replace 
            int replace=1+solve(a,b,i+1,j+1,dp);

            ans = min(ins,min(dlt,replace));
        }
        return dp[i][j] = ans;

    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(word1,word2,0,0,dp);
    }
};
