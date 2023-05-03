class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        vector<int>a;
        set<int>s1(nums1.begin(),nums1.end());
        set<int>s2(nums2.begin(),nums2.end());

        for(auto x : s1){
            if(s2.count(x)==0) a.push_back(x);
        }
        ans.push_back(a);
        a.clear();
        for(auto x : s2){
            if(s1.count(x)==0) a.push_back(x);
        }
        ans.push_back(a);
        a.clear();
        return ans;
    }
};
