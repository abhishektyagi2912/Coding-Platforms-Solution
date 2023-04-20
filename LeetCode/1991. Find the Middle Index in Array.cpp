class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum =0,s=0;
        for(int i : nums){
            sum += i;
        }
        for(int i = 0;i<nums.size();i++){
            sum -= nums[i];
            if(s == sum ) return i;
            s+=nums[i];
        }
        return -1;
    }
};
