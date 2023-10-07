#include <bits/stdc++.h> 
int findKthElement(vector<int> &arr1, vector<int> &arr2, int k){
    // Write your code here.
    vector<int> ans;
    int n = arr1.size();
    int m = arr2.size();
    for(int i =0;i<n;i++){
        ans.push_back(arr1[i]);
    }
    for(int i =0;i<m;i++){
        ans.push_back(arr2[i]);
    }
    sort(ans.begin(),ans.end());
    return ans[k-1];
}
