class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> str;
        
        for(int i= 0;i<s.length();i++){
            char c = s[i];

            if(c=='(') str.push(c);
            else{
                if(!str.empty() && str.top()=='(') str.pop();
                else str.push(c);
            }
        }

        // remaing is invalid element 
        int a=0;
        while(!str.empty()){
            a++;
            str.pop();
        }
        return a;
        
    }
};
