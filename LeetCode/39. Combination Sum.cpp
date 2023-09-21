class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>&sum,vector<int>&candidates,int i ,int target){
        if(i==candidates.size()){
            if(target==0)
            ans.push_back(sum);
            
            return;
        }

        if(target >= candidates[i]){
            sum.push_back(candidates[i]);
            solve(ans,sum,candidates,i,target-candidates[i]);
            sum.pop_back();
        }

        solve(ans,sum,candidates,i+1,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>sum;
        solve(ans,sum,candidates,0,target);

        return ans;
    }
};
