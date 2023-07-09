#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<int,vector<int>,greater<int>> minheap;
    for(int i=0;i<k;i++){
        int n = kArrays[i].size();
        for(int j=0;j<n;j++){
            minheap.push(kArrays[i][j]);
        }
    }
    vector<int> ans;
    while(!minheap.empty()){
        ans.push_back(minheap.top());
        minheap.pop();
    }
    return ans;
}
