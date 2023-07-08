class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        long long ans =0;
        priority_queue<long long,vector<long long>,greater<long long>> q;
        for(long long i=0;i<n;i++){
            q.push(arr[i]);
        }
        while(q.size()>1){
            long long a = q.top();
            q.pop();
            
            long long b = q.top();
            q.pop();
            
            long long sum = a+b;
            ans+=sum;
            q.push(sum);
        }
        return ans;
    }
};
