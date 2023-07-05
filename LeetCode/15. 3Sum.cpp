class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        // for no duplicate number 
        set<vector<int>> s;
        vector<vector<int>> ans;
        for(int i =0;i<n-2;i++){
            int l=i+1,h = n-1;
            while(l<h){
                if(nums[i]+nums[l]+nums[h]<0) l++;
                else if(nums[i]+nums[l]+nums[h]>0) h--;
                else{
                    s.insert({nums[i],nums[l],nums[h]});
                    l++;
                    h--;
                }
            }
        }
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};
