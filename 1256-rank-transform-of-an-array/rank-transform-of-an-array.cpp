class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return {};
        vector<int> ans;
        vector<int> dup = arr;
        sort(dup.begin(), dup.end());
        unordered_map<int,int> m;
        m[dup[0]]=1;
        int rank=1;
        for(int i=1; i<n; i++){
            if(dup[i]!=dup[i-1]) {
                rank++;
                m[dup[i]]=rank;
            }
            else m[dup[i]]=rank;
        }
        for(int i:arr){
            ans.push_back(m[i]);
        }
        return ans;
    }
};