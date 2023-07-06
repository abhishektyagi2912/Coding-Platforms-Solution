class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(auto x: nums) mp[x]++;
        for(auto y: mp){
            if(y.second>n/2){
                return y.first;
            }
        }
        return -1;
        
    }
};
