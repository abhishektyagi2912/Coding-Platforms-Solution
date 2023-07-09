class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int> ans;
        for(auto x :nums) mp[x]++;
        for(auto y: mp){
            if(y.second>1) {
                ans.push_back(y.first);
            }
        }
        return ans;
    }
};
