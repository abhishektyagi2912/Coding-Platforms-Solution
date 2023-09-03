#include<bits/stdc++.h>
class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        long long ans = 0;
        int i =0;
        while(s[i]== ' ' && i < s.length()){
            i++;
        }

        if(i < s.length() && (s[i] == '-' || s[i] == '+')){
            sign = (s[i]=='-')?-1:1;
            i++;
        }

        while(i < s.length() && isdigit(s[i])){
            ans = ans*10 + (s[i]-'0');

            if(ans*sign < INT_MIN) return INT_MIN;
            else if(ans*sign > INT_MAX) return INT_MAX;
            i++;
        }

        return ans*sign;
    }
};
