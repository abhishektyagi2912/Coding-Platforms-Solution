class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>counts;
        for(auto c : chars){
            counts[c]++;
        }
        int sol =0;
        for(string s: words){
            unordered_map<char,int>count;
            for(auto w: s){
                count[w]++;
            }
            bool a = true;
            for(auto ans : count){
                if(counts[ans.first]<ans.second){
                    a=false;
                    break;
                }
            }
            if(a) sol+= s.size();
        }
        return sol;
    }
};
