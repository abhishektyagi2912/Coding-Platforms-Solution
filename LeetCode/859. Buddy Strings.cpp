class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        if(s==goal){
            unordered_set<char>stt(s.begin(),s.end());
            return stt.size()<s.size();
        }
        vector<int> pos;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                pos.push_back(i);
            }
            if(pos.size()>2) return false;
        }
        if(pos.size()<2) return false;
        if(pos.size()) swap(s[pos[0]],s[pos[1]]);

        return s==goal;
    }
};
