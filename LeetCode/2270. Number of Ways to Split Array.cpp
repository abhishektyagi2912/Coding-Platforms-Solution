class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0;
        long long left = 0;
        long long right = 0;
        for(int i: nums){
            left +=i;
        }
        for(int i =0;i<nums.size()-1;i++){
            left -= nums[i];
            right+=nums[i];
            if(right>=left) ans++;
        }
        return ans;
    }
};
