class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long dp[n];
        dp[n-1] = questions[n-1][0];
        for(int i = n-2 ; i >=0 ;i--){
            dp[i] = questions[i][0];
            int jump = questions[i][1];
            if(jump + 1 + i < n){
                dp[i] += dp[i+jump +1];
            }
            dp[i] = max(dp[i] , dp[i+1]);
        }
        return dp[0];
    }
};
