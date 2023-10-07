class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        for(char c : s){
            if(c!='#') s1.push(c);
            else if (!s1.empty()) {
                s1.pop();
            }
        }
        for(char c : t){
            if(c!='#') s2.push(c);
            else if (!s2.empty()) {
                s2.pop();
            }
        }
        string a ,b;
        while(!s1.empty()){
            a = s1.top() + a;
            s1.pop();
        }
        
        while(!s2.empty()){
            b=s2.top()+b;
            s2.pop();
        }
        return a == b;
    }
};
