class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int>s;
        unordered_map<int,int> mp;
        for(auto x:arr) mp[x]++;
        for(auto y:mp){
            s.insert(y.second);
        }
        return s.size()==mp.size();
    }
};
