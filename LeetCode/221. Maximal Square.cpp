class Solution {
public:
    int solve(vector<vector<char>>& matrix, int i, int j, vector<vector<int>>&dp, int &maxi){
        if(j>=matrix[0].size() || i>= matrix.size()){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        int right = solve(matrix,i,j+1,dp,maxi);
        int digonal = solve(matrix,i+1,j+1,dp,maxi);
        int down = solve(matrix,i+1,j,dp,maxi);

        if(matrix[i][j] == '1'){
            dp[i][j] = 1 + min(right,min(down,digonal));
            maxi = max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        int maxi =0; 
        solve(matrix,0,0,dp,maxi);
        return maxi;
    }
};
