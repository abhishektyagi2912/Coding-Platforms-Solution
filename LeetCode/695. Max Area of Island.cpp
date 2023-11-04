class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid ){
        int count = 0;
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1){
            count++;

            // change the grid number so that it can't read again but not 0 & 1
            grid[i][j] = 2;

            count+=solve(i+1,j,grid);
            count+=solve(i-1,j,grid);
            count+=solve(i,j+1,grid);
            count+=solve(i,j-1,grid);

        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i =0;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(grid[i][j]==1){
                    int ans = solve(i,j,grid);
                    maxarea = max(ans,maxarea);
                }
            }
        }
        return maxarea;
    }
};
