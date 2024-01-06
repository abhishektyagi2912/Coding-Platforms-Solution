class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int n1 = matrix[0].size();
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<n1; j++){
                if(matrix[i][j]==0){
                    ans.push_back({i,j});
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            for(int c=0; c<n1;c++){
                matrix[ans[i][0]][c]=0;
            }
            for(int r=0;r<n;r++){
                matrix[r][ans[i][1]]=0;
            }
        }
        
    }
};
