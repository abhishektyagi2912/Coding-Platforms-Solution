class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        vector<pair<char,int>> v;
        for(auto x: mp){
            v.push_back({x.first,x.second});
        }

        sort(v.begin(),v.end(),[](const pair<char,int>&a, const pair<char,int>&b){
            return a.second>b.second;
        });

        string ans = "";
        for(auto x : v){
            for(int i =0;i<x.second;i++){
                ans+= x.first;
            }
        }
        return ans;
    }
};
