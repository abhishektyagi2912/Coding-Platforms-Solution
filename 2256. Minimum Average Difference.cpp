class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        int max=INT_MAX,res=0;
        long total =0,sum=0;
        for(int i :nums) total+=i;
        // cout<<total<<endl;
        for(int i =0;i<n-1;i++){
            sum+=nums[i];
            long curr = abs(sum/(i+1) - (total-sum)/(n-i-1));
            // cout<<curr<<endl;
            // res +=curr;
            if(curr<max){
                max = curr;
                res = i;
            }
        }

        return max>total/n?n-1:res;
    }
};
