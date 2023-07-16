class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i =0;
        int ans =0 , zeros=0;
        for(int j =0;j<nums.size();j++){
            if(nums[j]==0) zeros++;

            while(zeros>1){
                if(nums[i]==0) zeros--;
                i++;
            }

            ans = max(ans,j-i);
        }
        return ans;
    }
};
