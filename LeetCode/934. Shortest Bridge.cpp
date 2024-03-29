class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& vis, queue<pair<int, int>>& q) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (row >= n || col >= m || row < 0 || col < 0 || vis[row][col] || grid[row][col] == 0) {
            return;
        }
        
        q.push({row, col});
        vis[row][col] = true;
        
        dfs(grid, row + 1, col, vis, q);
        dfs(grid, row - 1, col, vis, q);
        dfs(grid, row, col - 1, vis, q);
        dfs(grid, row, col + 1, vis, q);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        
        bool found = false;
        
        // Step 1: Find the first island
        for (int row = 0; row < n; row++) {
            if (found) {
                break;
            }
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 1) {
                    dfs(grid, row, col, vis, q);
                    found = true;
                    break;
                }
            }
        }
        
        // Step 2: Expand the island and find the second island using BFS
        int flips = 0;
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int size = q.size();
            
            while (size > 0) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for (const auto& direction : directions) {
                    int newRow = row + direction[0];
                    int newCol = col + direction[1];
                    
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol]) {
                        if (grid[newRow][newCol] == 1) {
                            return flips;
                        }
                        
                        q.push({newRow, newCol});
                        vis[newRow][newCol] = true;
                    }
                }
                
                size--;
            }
            
            flips++;
        }
        
        return -1;
    }
};
