class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> rowMin, colMax, ans;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Find the minimum element in each row
        for(int i = 0; i < rows; i++) {
            int mini = *min_element(matrix[i].begin(), matrix[i].end());
            rowMin.push_back(mini);
        }

        // Find the maximum element in each column
        for(int j = 0; j < cols; j++) {
            int maxi = matrix[0][j];
            for(int i = 1; i < rows; i++) {
                if(matrix[i][j] > maxi) {
                    maxi = matrix[i][j];
                }
            }
            colMax.push_back(maxi);
        }

        // Find the lucky numbers
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};
