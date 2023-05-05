class Solution {
    int isvowel(char s){
        return (s=='a' ||s=='e' ||s=='i' ||s=='o' ||s=='u') ?1:0;
    }
public:
    int maxVowels(string s, int k) {
        int count=0,r=0;
        //first window
        for(int i =0;i<s.size();i++){
            count += isvowel(s[i]);
            if(i>=k){
                count -= isvowel(s[i-k]);
            }
            r = max(r,count);
        }
        
        return r;
    }
};
