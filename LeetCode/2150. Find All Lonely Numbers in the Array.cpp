class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int> ans;
        for(auto x :nums) mp[x]++;
        
        for(auto y: mp){
            int a = y.first;
            int b = y.second;

            if(b==1 && mp.count(a+1)==0 && mp.count(a-1)==0) ans.push_back(a);
        }
        return ans;
    }
};
