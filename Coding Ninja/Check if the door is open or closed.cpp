#include <bits/stdc++.h> 
bool isEvenFactor(int n){
    int a = sqrt(n);
    if((a*a)==n) return false;
    return true;
}
string doorStatus(int n) {
    // Write your code here.
    string ans = "";
    for(int i =1;i<=n;i++){
        if(isEvenFactor(i)) ans.append("0");
        else ans.append("1");
    }
    return ans;
}
