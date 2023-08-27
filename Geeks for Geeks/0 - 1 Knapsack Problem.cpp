lass Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int w, int wt[], int val[], int n, vector<vector<int>>& dp){
        if(n==0){
            if(wt[0]<=w){
                return val[0];
            }
            else{
                return 0;
            }
        }
        if(dp[n][w] != -1){
            return dp[n][w];
        }
        int include = 0;
        if(wt[n]<=w){
            include = val[n]+solve(w-wt[n],wt,val,n-1,dp);
        }
        int exclude = solve(w,wt,val,n-1,dp);
        dp[n][w]=max(include,exclude);
        return dp[n][w];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n, vector<int>(W+1,-1));
       return solve(W,wt,val,n-1,dp);
    }
};
