class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count =0;
        int n =grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                bool match = 1;
                for(int l =0;l<n;l++){
                    if(grid[i][l] != grid[l][j]){
                        match = 0;
                        break;
                    }
                }
                count+=match;
                
            }
        }
        return count;
    }
};
