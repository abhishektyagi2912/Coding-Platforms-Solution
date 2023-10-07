#include <bits/stdc++.h> 
vector<int> toggleBulbs(int n){
    // Write your code here.
    vector<int> ans;
    int i=1;
    while(i*i <=n){
        ans.push_back(i*i);
        i++;
    }
    return ans;
}
