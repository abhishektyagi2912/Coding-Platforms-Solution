class Solution {
public:
    int partitionString(string str) {
        int ans = 1;
        set<int> s;
        for(auto c : str){
            if(s.find(c)!=s.end()){
                ans++;
                s.clear();
            }
            s.insert(c);
        }
        return ans;
    }
};
