class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        unordered_set<int> st;
        for(auto x : nums){
            st.insert(x);
        }
        int count =1;
        while(count<=n){
            if(!st.count(count)){
                ans.push_back(count);
            }
            count++;
        }
        return ans;
    }
};
