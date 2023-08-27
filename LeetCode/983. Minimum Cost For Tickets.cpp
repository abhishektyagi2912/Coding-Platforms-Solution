class Solution {
public:
    int solve(int n,vector<int>& days, vector<int>& costs, vector<int>&dp,int index){
        if(index>=n){
            return 0;
        }
        if(dp[index]!= -1){
            return dp[index];
        }
        int first = costs[0]+solve(n,days,costs,dp,index+1);
        
        int i;
        // 7days
        for(i=index; i<n && days[i]<days[index]+7;i++);

        int sec = costs[1] + solve(n,days,costs,dp,i);

        // 30 days
        for(i=index; i<n && days[i]<days[index]+30;i++);

        int third = costs[2] + solve(n,days,costs,dp,i);

        dp[index] = min(first,min(sec,third));
        return dp[index];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1,-1);
        return solve(n,days,costs,dp,0);
    }
};
