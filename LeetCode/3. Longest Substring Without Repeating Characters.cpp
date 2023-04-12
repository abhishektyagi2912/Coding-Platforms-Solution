class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), res = 0;
        unordered_map<char,int> m;
        for(int j=0,i=0;j<n;j++){
          if(m[s[j]]>0) i = max(m[s[j]],i);
          res = max(res,j-i+1);
          m[s[j]]=j+1;
        }
        return res;
        
    }
};
