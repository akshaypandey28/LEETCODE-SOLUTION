class Solution {
public:
    //if there are even negative number then take the absolute value of matrix and add it to the sum variable
    //if odd then shift the negative sign to the minimum absolute value of matrix so that the minimum absolute can hold the negative sign and maximum sum can be calculated
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        long long sum=0;
        int minAbsVal=INT_MAX;
        int count=0; //count the negative number in the matrix
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                sum+=abs(matrix[i][j]);

                if(matrix[i][j] < 0) count++;

                minAbsVal=min(minAbsVal,abs(matrix[i][j]));
            }
        }
        if(count%2==0) return sum;
        return sum-(2*minAbsVal);
    }
};