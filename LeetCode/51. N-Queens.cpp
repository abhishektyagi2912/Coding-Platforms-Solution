class Solution {
public:
void addSolution(vector<vector<int>> &board,vector<vector<string>>& ans,int n){
    vector<string> temp;
    for(int i =0;i<n;i++){
        string s;
        for(int j=0;j<n;j++){
            if(board[i][j]==1){
                s.push_back('Q');
            }
            else{
                s.push_back('.');
            }
        }
        temp.push_back(s);
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n){
    int x = row;
    int y = col;

    while(y>=0){
        if(board[x][y]==1){
            return false;
        }
        y--;
    }
    // check diagonal
    x= row;
    y= col;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }

    x= row;
    y= col;
    while(x<n && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x++;
        y--;
    }
    return true;
}
void solve(int col, vector<vector<int>> &board,vector<vector<string>>& ans,int n ){
    if(col == n){
        // ans.push_back(board);
        addSolution(board,ans,n);
        return;
    }

    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col] = 1;
            solve(col+1,board,ans,n);
            board[row][col] = 0;
        }
    }


}
    vector<vector<string>> solveNQueens(int n) {
        // vector<string> board(n,string(n,'.'));
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<vector<string>> ans;

        solve(0,board,ans,n);

        return ans;
    }
};
