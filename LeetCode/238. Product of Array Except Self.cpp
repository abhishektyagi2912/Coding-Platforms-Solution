class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int num = 1;
        for(int i =0;i<nums.size();i++){
            ans[i]=num;
            num = num*nums[i];
        }
        num=1;
        for(int i =nums.size()-1;i>=0;i--){
            ans[i]=ans[i]*num;
            num = num*nums[i];
        }
        return ans;
    }
};
