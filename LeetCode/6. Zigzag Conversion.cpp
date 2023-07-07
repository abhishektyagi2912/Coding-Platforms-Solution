class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ans(numRows);
        if(numRows == 1){
            return s;
        }
        bool flag = false;
        int i =0;
        for(auto x : s){
            ans[i]+=x;
            if(i== 0 || i == numRows - 1){
                flag = !flag;
            }
            if(flag) i++;
            else i--;
        }
        string a = "";
        for(auto str : ans){
            a+=str;
        }
        return a;
    }
};
