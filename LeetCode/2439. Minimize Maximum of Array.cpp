class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        //in this we take 3+0/1+0 = 3 and 3+7=10 -> 10+1/1+1= 5 
        long ans = 0, sum = 0;
        for(int i =0 ; i< nums.size(); i++){
            sum+=nums[i];
            ans = max(ans,(sum+i)/(i+1));
        }
        return ans;
    }
};
