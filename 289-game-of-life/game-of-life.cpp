class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copy=board;

        int n=board.size();
        int m=board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int count=0; //for live cells
                if(i-1>=0 and copy[i-1][j]==1) count++; //up 
                if(i+1<n and copy[i+1][j]==1) count++; //down 
                if(j-1>=0 and copy[i][j-1]==1) count++; //left 
                if(j+1<m and copy[i][j+1]==1) count++; //right 

                if(i-1>=0 and j+1<m and copy[i-1][j+1]==1) count++; //top right
                if(i+1<n and j+1<m and copy[i+1][j+1]==1) count++; //bottom right
                if(i-1>=0 and j-1>=0 and copy[i-1][j-1]==1) count++; //top left
                if(i+1<n and j-1>=0 and copy[i+1][j-1]==1) count++; //bottom left

                if(copy[i][j]==0 and count==3) board[i][j]=1; //dead cells
                else if(copy[i][j]==1 and ( count==2 or count==3 ) ) board[i][j]=1;//live cells
                else if(copy[i][j]==1 and count>3) board[i][j]=0; //live cells dies
                else board[i][j]=0; //live cells dies 
            }
        }
        return ;
    }
};