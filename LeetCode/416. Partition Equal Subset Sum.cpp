class Solution {
public:
    bool solve(int index, vector<int>&nums, int target, vector<vector<int>>&dp){
        if(index>=nums.size()) return 0;
        if(target<0) return 0;
        if(target == 0) return 1;
        if(dp[index][target]!=-1) return dp[index][target];

        int include = solve(index+1,nums,target-nums[index],dp);
        int exclude = solve(index+1,nums,target,dp);

        dp[index][target] = include || exclude;
        return dp[index][target];

    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        // check sum is even or odd
        if(sum&1) return false;

        int target = sum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return solve(0,nums,target,dp);
    }
};
