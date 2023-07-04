class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x : nums) mp[x]++;
        for(auto ans:mp){
            if(ans.second==1){
                return ans.first;
            }
        }
        return 0;
    }
};
