typedef long long ll;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>>maxHeap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >minHeap;
        for(int i = 0; i<nums1.size(); i++)maxHeap.push({nums2[i],nums1[i]});
        ll ans = 0, total = 0;
        while(!maxHeap.empty()){
            minHeap.push({maxHeap.top().second, maxHeap.top().first});
            total += maxHeap.top().second;
            if(minHeap.size() > k){
                total -= minHeap.top().first;
                minHeap.pop();
            }
            if(minHeap.size() == k) ans = max(ans, total * maxHeap.top().first);
            maxHeap.pop();
        }

        return ans;
        
    }
};
