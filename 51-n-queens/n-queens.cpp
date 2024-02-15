class Solution {
public:
    vector<vector<string>> grid;
    bool canPlaceQueen(int Row,int col,vector<vector<char>> &ans){
    for(int i=Row-1; i>=0; i--){ //is someOne attacking from vertically up column check
        if(ans[i][col]=='Q'){ //we are attacked
            return false;
        }
    }
    for(int i=Row-1,j=col-1; i>=0&&j>=0; i--,j--){  //diagonally left
        if(ans[i][j]=='Q'){ //we are attacked
            return false;  
        }
    }
    for(int i=Row-1,j=col+1; i>=0&&j<ans.size(); i--,j++){ //diagonally right
        if(ans[i][j]=='Q'){ //we are attacked
            return false;   
        }
    }
    return true;   //no attack found
}
    void nQueens(int currRow,int n,vector<vector<char>> &ans){ //,string &s
        if(currRow==n){
            vector<string> v;
            for(int i=0; i<n; i++){
                string s="";
                for(int j=0; j<n; j++){
                    s.push_back(ans[i][j]);
                }
                v.push_back(s);
            }
            grid.push_back(v);
        }
        for(int col=0; col<n; col++){
            if(canPlaceQueen(currRow,col,ans)){
                ans[currRow][col]='Q';
                nQueens(currRow+1,n,ans);
                ans[currRow][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> ans(n,vector<char> (n,'.'));
        //string s="";
        nQueens(0,n,ans);
        //vector<vector<string>> 
        return grid;
    }
};