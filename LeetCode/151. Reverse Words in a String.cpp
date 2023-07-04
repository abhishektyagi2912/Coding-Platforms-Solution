class Solution {
public:
    string reverseWords(string s) {
        
        if(s.size() == 0)
        {
            return s;
        }

        stack <string> stk;
        string result = "";

        for(int i = 0 ; i < s.size() ; i++)
        {
            string temp;
            if(s[i] == ' ')
            {
                continue;
            }

            while(i < s.size() && s[i] != ' ')
            {
                temp = temp + s[i];
                i++;
            }
            stk.push(temp);
        }

        while(!stk.empty())
        {
            result = result + stk.top();
            stk.pop();

            if(!stk.empty())
            {
                result = result + " ";
            }
        }
        return result;
    }
};
