class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> ans(stones.begin(),stones.end());
        // int x = *max_element(stones.begin(),stones.end());
        // int y =  *max_element(stones.begin(),stones.end());
        // sort(stones.begin(),stones.end());
        while(ans.size()>1){
            int a = ans.top();
            ans.pop();
            int b = ans.top();
            ans.pop();

            if(a != b) ans.push(a-b);
        }
        return ans.empty() ? 0 : ans.top();
    }
        
};
