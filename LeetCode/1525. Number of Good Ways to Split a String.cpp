class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> mp1,mp2;
        int ans =0;
        mp1[s[0]]++;
        for(int i =1;i<s.size();i++){
            mp2[s[i]]++;
        }
        if(mp1.size() == mp2.size()) ans++;

        for(int i = 1; i<s.size()-1; i++){
            if(mp1.size() == mp2.size()) ans++;
            mp2[s[i]]--;
            mp1[s[i]]++;

            if(mp2[s[i]]==0)
            mp2.erase(s[i]);

        }
        return ans;
    }
};
