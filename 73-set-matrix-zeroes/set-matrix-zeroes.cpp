class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0; //marking the ith row zero
                    if(j!=0) matrix[0][j]=0; //marking the jth col zero
                    else col0=0;
                }
            }
        }
    //from (1,1) to (n-1,m-1)
        for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // checking  for col and row
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
         }
        }

        if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    }
};