class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0) return nums;
        
        vector<int> ans(n,-1);
        if(2*k+1 > n ) return ans;

        vector <long long> prefix(n+1,0);
        for(int i =1;i<=n;i++){
            long long ans = prefix[i-1]+nums[i-1];
            prefix[i] = ans;
        }

        // n-k because i need only iterate to last 3 otherwise it in not valid
        // start with k is because i nedd equal left and right side 
        for(int i = k;i<(n-k);i++){
            int left = i-k, right = i + k;
            long long sum = prefix[right+1] - prefix[left];
            int average = sum / (2*k+1);
            ans[i] =  average;
        }
        return ans ;
    }
};
