class Solution {
public:
    string removeStars(string s) {
        // // this is by using stack and my logic
        // stack<char>st;
        // for(int i=0;i<s.size();i++){
        //     if(s[i] == '*') st.pop();
        //     else st.push(s[i]);
        // }
        // string ans ="";
        // while(!st.empty()){
        //     ans += st.top();
        //     st.pop();
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;
        string ans ="";
        for(int i = 0;i<s.size();i++){
            if(s[i]=='*') ans.pop_back();
            else ans.push_back(s[i]);
        }
        return ans;
    }
};
