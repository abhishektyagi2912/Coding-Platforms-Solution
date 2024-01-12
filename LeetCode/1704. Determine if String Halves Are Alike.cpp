class Solution {
public:
    int countVowel(string s){
        // ch arr = ["a","e","i","o","u"];
        int n = 0;
        for(int i=0;i<s.size();i++){
            if(tolower(s[i])=='a' || tolower(s[i])=='e' || tolower(s[i])=='i' || tolower(s[i])=='o'|| tolower(s[i])=='u') n++;
        }
        return n;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        string s1 = "";
        string s2 = "";
        for(int i =0;i<n/2;i++){
            s1+=s[i];
        }
        for(int i=n/2 ;i<n;i++){
            s2+=s[i];
        }

        cout<<s1<<" "<<s2;
        if(countVowel(s1)==countVowel(s2)) return true;
        return false;
    }
};
