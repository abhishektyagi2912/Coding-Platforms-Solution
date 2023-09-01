class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        long long maxi=0,sum =0;

        for(int i =0;i<k-1;i++){
            sum+=nums[i];
            mp[nums[i]]++;
        }

        for(int i = k-1; i< n ;i++){
            sum+=nums[i];
            mp[nums[i]]++;

            if(mp.size() == k) maxi = max(sum,maxi);

            // if size is one the remove it because i include this 
            if(mp[nums[i-k+1]] == 1) mp.erase(nums[i-k+1]);

            else mp[nums[i-k+1]]--;

            // save the output and move the window
            sum-=nums[i-k+1];
        }
        return maxi;
    }
};
