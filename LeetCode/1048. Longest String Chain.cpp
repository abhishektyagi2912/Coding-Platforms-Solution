class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string &a, const string& b ){
            return a.length() < b.length();
        });
        int ans =1;
        unordered_map<string,int> mp;
        for(auto w: words){
            int curr =1;
            for(int i=0;i<w.size();i++){
                string s = w.substr(0,i)+w.substr(i+1);
                if(mp[s]) curr = max(curr,mp[s]+1);
            }
            mp[w] = curr;
            ans = max(ans,curr);
        }
        return ans;
    }
};
