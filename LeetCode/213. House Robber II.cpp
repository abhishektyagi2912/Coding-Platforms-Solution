class Solution {
    int solve(vector<int>nums){
        int k = nums.size();
        int ans = 0,prev=0;
        for(int i =0;i<k;i++){
            int a = max(prev+nums[i],ans);
            prev = ans;
            ans = a;
        }
        return ans;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> ans1;
        vector<int> ans2;
        for(int i =0;i<n;i++){
            if(i!=n-1) ans1.push_back(nums[i]);
            if(i != 0) ans2.push_back(nums[i]);
        }
        return max(solve(ans1), solve(ans2));
    }
};
