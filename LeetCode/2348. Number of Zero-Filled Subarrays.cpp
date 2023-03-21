class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int a = nums.size();
        long long ans =0 , b=0;
        for(int i =0;i<=a; i++){
            if(i<a && nums[i]==0) b++;
            else {
                //hum return krenge uski length jha tk zero aya h 
                ans += b*(b+1)/2;  //length of subarray 
                b=0;
            }
        }
        return ans;
    }
};
