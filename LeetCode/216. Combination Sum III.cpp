class Solution {
public:
    void solve(int start, vector<vector<int>>& ans, vector<int>&sum,int k, int n){
        if(sum.size()==k){
            if(n==0){
                ans.push_back(sum);
            }
            return;
        }

        for(int i=start;i<=9;i++){
            if(i>n) break;
            sum.push_back(i);
            solve(i+1,ans,sum,k,n-i);
            // cout<<n-i<<endl;
            sum.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>sum;
        solve(1,ans,sum,k,n);
        return ans;
    }
};
