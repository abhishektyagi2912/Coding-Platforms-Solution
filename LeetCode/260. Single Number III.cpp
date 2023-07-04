class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int> mp;
        for(int x : nums) mp[x]++;
        for(auto y:mp){
            if(y.second==1){
                ans.push_back(y.first);
            }
        }
        return ans;
    }
};
