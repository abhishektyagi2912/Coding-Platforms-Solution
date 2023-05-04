class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> a,b;
        for(int i=0; i<senate.size();i++){
            if(senate[i]=='R') a.push(i); /// pposition of the i
            else b.push(i);
        }
        while(!a.empty()&&!b.empty()){
            int rd = a.front();
            int dr = b.front();
            a.pop();b.pop();

            if(rd<dr) a.push(rd+senate.size());
            else b.push(dr+senate.size());

        }
        if(a.empty()) return "Dire";
        else return "Radiant";
    }
};
