class Solution {
public:
    void solve(int r, int l, int n, vector<string>&ans, string s){
        if(s.size()==n*2){
            ans.push_back(s);
            return;
        }

        if(r < n) solve(r+1,l,n,ans,s+"(");
        if(l < r) solve(r,l+1,n,ans,s+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0,0,n,ans,"");
        return ans;
    }
};
