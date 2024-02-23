class Solution {
public:
    bool canBePlace(vector<vector<char>> &board,int row,int col,char num){
    for(int j=0;j<9; j++){
        if(board[row][j]==num){
            return false;
        }
    }
    for(int i=0;i<9; i++){
        if(board[i][col]==num){
            return false;
        }
    }
    int r=(row/3)*3;
    int c=(col/3)*3;
    for(int i=r; i<(r+3); i++){
        for(int j=c; j<(c+3); j++){
            if(board[i][j]==num){
                return false;
            }
        }
    }
    return true;
}
    bool sudoko(vector<vector<char>> &board,int row,int col){
        if(row==9) return true;
        if(col==9) return sudoko(board,row+1,0);
        if(board[row][col]=='.'){
        for(int num=1; num<=9; num++){
            if(canBePlace(board,row,col,'0'+num)){
                board[row][col]='0'+num;
                bool res=sudoko(board,row,col+1); //iska mtlb hai ki aage ka bacha hua sudoku solve ho gya to res=true hoga
                //and in this case aage ka kuch bhi check krne ka jrurat nhi hai aur return kr jana hai 
                //for this if statement is used
                if(res){
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;
    }
    else return sudoko(board,row,col+1);
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudoko(board,0,0);
    }
};