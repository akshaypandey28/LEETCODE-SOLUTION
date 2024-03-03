class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),cmp);
        vector<vector<int>> ans;
        vector<int> temp=v[0];
        for(int i=1; i<v.size(); i++){
            if(temp[1]>=v[i][0]) {
                temp[1]=max(temp[1],v[i][1]);
            }
            else{
                ans.push_back(temp);
                temp=v[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};