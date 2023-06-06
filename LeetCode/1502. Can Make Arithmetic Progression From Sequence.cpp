class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans = abs(arr[1]-arr[0]);
        for(int i =2;i<arr.size();i++){
            if (ans != abs(arr[i]-arr[i-1])) return false;
        }
        return true;
    }
};
