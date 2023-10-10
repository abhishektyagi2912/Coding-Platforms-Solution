#include <bits/stdc++.h>
class Solution {
public:
    int solve(int i , string s, set<string>& st, vector<int>&dp){
        if(i==s.size()) return 1;
        if(dp[i]!= -1) return dp[i];
        string temp;
        for(int j = i;j<s.size();j++){
            temp += s[j];
            if(st.find(temp)!=st.end()){
                if (solve(j+1,s,st,dp)) return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1,-1);
        set<string> st;

        for(auto a: wordDict) st.insert(a);
        return solve(0,s,st,dp);
    }
};
