class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0; i<queries.size(); i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int x=0;
            for(int j=l; j<=r; j++) x^=arr[j];
            ans.push_back(x);
        }
        return ans;
    }
};