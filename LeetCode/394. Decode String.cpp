class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i =0;i<s.size();i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }
            else{
                // idhr closing bracket aya 
                string curr = "";
                while(st.top()!='['){
                    curr=st.top()+curr;
                    st.pop();
                }
                st.pop(); //[ y bhi to hoyega 
                string num ="";
                //char wise gya hoga to ab push krna number
                while(!st.empty() && isdigit(st.top())){
                    num=st.top()+num;
                    st.pop();
                }
                //change to int 
                int n = stoi(num);
                while(n--){
                    for(int i =0;i<curr.size();i++){
                        st.push(curr[i]);
                    }
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};
