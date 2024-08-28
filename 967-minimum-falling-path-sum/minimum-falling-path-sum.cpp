class Solution {
public:
    vector<vector<int>> dp;
    int minFallingPathSum(vector<vector<int>>& m) {
        int n = m.size();
        dp.clear();
        dp.resize(n, vector<int>(n, INT_MAX)); 

        int mini = INT_MAX;
        for (int j = 0; j < n; j++) dp[0][j]=m[0][j];

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int up=m[i][j]+dp[i-1][j];
                int left=m[i][j];
                if(j-1>=0) left+=dp[i-1][j-1];
                else left=INT_MAX;
                int right=m[i][j];
                if(j+1<n) right+=dp[i-1][j+1];
                else right=INT_MAX;
                dp[i][j]=min({up,left,right});
            }
        }
        for(int j=0; j<n; j++) mini=min(mini,dp[n-1][j]);
        return mini;
    }
};
