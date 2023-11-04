class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(locked.size()&1) return false;
        int open =0 ,close=0;
        for(int i =0;i<locked.size();i++){
            if(locked[i]=='0' || (locked[i]=='1' && s[i]=='(')){
                open++;
            }
            else close++;
            if(close>open) return false;
        }
        open=0,close=0;
        for(int i =locked.size()-1;i>=0;i--){
            if(locked[i]=='0' || (locked[i]=='1' && s[i] == ')')){
                close++;
            }
            else open++;
            if(open>close) return false;
        }
        return true;
    }
};
