class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int ans =1;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            if(nums[i]<=0){
                continue;
            }
            else{
                if(nums[i]== ans) ans++;
            }
        }
        return ans;
    }
};
