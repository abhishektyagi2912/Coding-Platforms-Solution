class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i:nums) m[i]++;

        priority_queue<pair<int,int>> arr;
        for(auto i:m) arr.push({i.second,i.first});

        vector<int>ans;
        while(!arr.empty())
        {
            ans.push_back(arr.top().second);
            arr.pop();
            k--;
            if(k==0)break;
        }
        

        return ans;
    }
};
