class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        unordered_set<int> st;
        int ans=0;

        for(auto x : s){
            mp[x]++;
        }
        for(auto x: mp){
            int i = x.second;
            while(i>0 && st.find(i)!=st.end()){
                i--;
                ans++;
            }
            st.insert(i);
        }
        return ans;
    }
};
