class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char l) {
        for (int i = 0; i < board.size(); i++) {
            if (board[row][i] == l  || board[i][col] == l) {
                return false;
            }
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == l) {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    char temp = board[i][j];

                    board[i][j] = '.';

                    if(!isSafe(i,j,board,temp)) return false;

                    board[i][j] = temp;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }
};
