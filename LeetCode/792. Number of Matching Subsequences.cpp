class Solution {
public:
    bool isSubsequnece(string s, string t){
        int match =0;
        int i=0;
        int j=0;
        while(i<s.size()&&j<t.size()){
            if(s[i]==t[j]){
                match++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return (match == s.size());
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count =0;
        unordered_map<string,int> mp;
        for(auto &str : words) mp[str]++;
        for(auto &ps : mp){
            if(isSubsequnece(ps.first,s)) count+=ps.second;
        }
        return count;        
    }
};
