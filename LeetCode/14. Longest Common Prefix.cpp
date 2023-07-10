class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(),strs.end());
        string str = strs[0];
        string str1 = strs[strs.size()-1];

        for(int i=0 ;i<strs[0].size();i++){
            if(str[i] == str1[i]) ans += str[i];
            else break;
        }
        return ans;
    }
};
