class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int ans =0,i=0;
        if(n == 1) return 1;
        while(i<n-1){
            if(nums[i]==nums[i+1]){
                ans++;  
                i++;         
            }else i+=2;
        }
        if((n-ans)%2) ans++;
        return ans;
    }
};
