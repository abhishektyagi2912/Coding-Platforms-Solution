#include <bits/stdc++.h> 
vector<int> prevSmall(vector<int> arr, int n) {
    // Write your code here.
    vector<int>v;
    stack<int>st;
    for(auto x:arr){
        while(!st.empty() && st.top()>=x)
            st.pop();
        if(st.size()==0)
            v.push_back(-1);
        else
            v.push_back(st.top());
        st.push(x);
    }
    return v;
}
