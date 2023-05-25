class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0) return 1;
        vector<double>dp(k+maxPts+1, -1);
        double windowSum = 0;
        for(int i = k; i<k+maxPts; i++) windowSum += (i<=n?1:0);
        k--;
        while(k>-1){
            dp[k] = windowSum / (double)maxPts;
            double remove = 0;
            if(k+maxPts<=n) remove = dp[k+maxPts] == -1 ?1:dp[k+maxPts] ;
            windowSum += dp[k] - remove;
            k--;
        }
        return dp[0];
    }
};
