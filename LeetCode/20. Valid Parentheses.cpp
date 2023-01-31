class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        for(auto i : s){
            // for opening bracket
            if(i=='(' || i == '[' || i=='{'){
                str.push(i);
            }
            else{
                if(!str.empty()){
                    char top = str.top();
                    if( (i == ')' && top == '(') || 
                     ( i == '}' && top == '{') || 
                     (i == ']' && top == '[') ) {
                      str.pop();
                    }
                    else{
                        return false;
                    }
                }
                else return false; 
            }
        }
        if(str.empty()) return true;
        else return false;
    }
};
