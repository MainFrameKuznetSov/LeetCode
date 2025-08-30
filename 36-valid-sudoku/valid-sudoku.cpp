class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int>row(9,0),col(9,0),boxes(9,0);
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j) 
            {
                if(board[i][j]!='.') 
                {
                    int bit=1<<(board[i][j]-'0'),index=i/3*3+j/3;
                    if(row[i]&bit || col[j]&bit || boxes[index]&bit)
                        return false;
                    row[i]|=bit;
                    col[j]|=bit;
                    boxes[index]|=bit;
                }
            }
        }
        return true;
    }
};