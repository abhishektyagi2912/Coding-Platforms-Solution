class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> map;
        int count = 0 ;

        for (const auto& domino : dominoes){
            int a = min(domino[0], domino[1]);
            int b = max(domino[0], domino[1]);
                
            int hash = a * 10 + b;
            // cout<<hash<<endl;
            count += map[hash];
            // cout<<count<<endl;
                
           map[hash]++;     
        }

        return count;
    }
};
