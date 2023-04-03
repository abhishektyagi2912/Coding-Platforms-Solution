class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        int n = prices.size();
        vector<int> ans(n);
        s.push(-1);

        for(int i = n-1 ; i>=0; i--){
            int curr = prices[i];
            while(s.top()>curr){
                s.pop();
            } 
            if(s.top() == -1) ans[i] = prices[i];
            else ans[i] = prices[i] - s.top();
            s.push(curr);
        }
        return ans;
    }
};
