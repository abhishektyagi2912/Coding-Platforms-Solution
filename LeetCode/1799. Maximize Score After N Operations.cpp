class Solution {
public:
int n;
int solve(vector<int>&nums, vector<bool>&vis, int op_No, unordered_map<vector<bool>,int>&m){
    if(m.find(vis)!=m.end()) return m[vis];
    int max_score=0;


    for(int i=0;i<n-1;i++){
        if(vis[i]) continue;
        for(int j=i+1;j<n;j++){
            if(vis[j]) continue;
            vis[i]=true;
            vis[j]=true;
            int score= op_No * __gcd(nums[i],nums[j]);
            int rem_score= solve(nums,vis,op_No+1,m);
            vis[i]=false;
            vis[j]=false;
            max_score=max(max_score,score+rem_score);
        }
    }

    return m[vis]=max_score;
}
    int maxScore(vector<int>& nums) {
        n=nums.size();
       

        vector<bool>vis(n+1,false);
        unordered_map<vector<bool>,int>m;

        return solve(nums,vis,1,m);

    }
};
