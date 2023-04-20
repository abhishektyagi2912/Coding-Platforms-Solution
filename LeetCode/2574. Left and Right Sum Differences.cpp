class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> a,b,ans;
        // vector<int> b(n,0);
        // vector<int> ans;
        a.emplace_back(0);
        b.emplace_back(0);
        int sum =0;
        for(int i=0;i<n-1;i++){
            sum+=nums[i];
            a.emplace_back(sum);
        }
        sum=0;
        for(int i=n-1;i>0;i--){
            sum += nums[i];
            b.emplace_back(sum);
        }
        reverse(b.begin(),b.end());
        for(int i =0; i<a.size();i++){
            ans.emplace_back(abs(a[i]-b[i]));
        }
        return ans;
    }
};
