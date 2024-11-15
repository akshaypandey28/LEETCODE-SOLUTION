class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        if (m * n != o.size()) return {}; 

        vector<vector<int>> ans(m, vector<int>(n));
        int r = 0, c = 0;

        for (int i = 0; i < o.size(); i++) {
            ans[r][c] = o[i];
            c++; 
            if (c == n) { 
                r++;
                c = 0; 
            }
        }
        return ans;
    }
};
