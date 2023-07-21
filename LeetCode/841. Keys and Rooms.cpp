class Solution {
public:
void solve(int node,vector<vector<int>>& rooms,vector<bool>&visited){
    visited[node]=true;
    for(int i =0;i<rooms[node].size();i++){
        if(!visited[rooms[node][i]]){
            solve(rooms[node][i],rooms,visited);
        }
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>visited(rooms.size());
        solve(0,rooms,visited);

        for(auto x: visited){
            if(x == false) return false;
        }
        return true;
    }
};
