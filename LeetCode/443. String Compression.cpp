class Solution {
public:
    int compress(vector<char>& chars) {
        int i =0;
        for(int j=1,count=1;j<=chars.size();j++,count++){
            if(j==chars.size()||chars[j]!=chars[j-1]){
                chars[i++] = chars[j-1];
                if(count>=2){
                    for(char x: to_string(count)){
                        chars[i++]=x;
                    }
                }
                count=0;
            }
        }
        return i;
    }
};
