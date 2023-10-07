void solve(long long n, long long temp, vector<long long>&ans){
    if(n>temp){
        if(temp>0){
            ans.push_back(temp);
        }

        solve(n, temp*10 +2, ans);
        solve(n, temp*10 +5, ans);
    }
    return;
}

vector<long long> createSequence(long long n){
    // Write your code here.
    vector<long long> ans;
    if(n==2){
        ans.push_back(2);
        return ans;
    }
    long long temp = 0;
    solve(n,temp,ans);
    sort(ans.begin(),ans.end());
    return ans;
}
