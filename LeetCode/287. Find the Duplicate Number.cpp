class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x :nums) mp[x]++;
        int n;
        for(auto y: mp){
            if(y.second>1) {
                n = y.first;
            }
        }
        return n;
    }
};
