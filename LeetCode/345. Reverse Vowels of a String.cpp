class Solution {
public:
bool isVowel(char ch){
        if(ch == 'a' || ch == 'A')   return true;
        if(ch == 'e' || ch == 'E')   return true;
        if(ch == 'i' || ch == 'I')   return true;
        if(ch == 'o' || ch == 'O')   return true;
        if(ch == 'u' || ch == 'U')   return true;

        return false;
    }
    string reverseVowels(string s) {

        int low =0;
        int high = s.size();
        while(low<high){
            if(isVowel(s[low]) == false)
                low++;

            if(isVowel(s[high]) == false)
                high--;

            if(isVowel(s[low]) && isVowel(s[high])){
                swap(s[low], s[high]);
                low++;
                high--;
            }
        }
        return s;
    }
};
