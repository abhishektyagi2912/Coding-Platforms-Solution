class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> a(26,0),b(26,0);
        set<char>aa,bb;
        for(char &c:word1){
            a[c-'a']++;
            aa.insert(c);
        }
        for(char &c:word2){
        b[c-'a']++;
        bb.insert(c);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a==b&&aa==bb;
    }
};
