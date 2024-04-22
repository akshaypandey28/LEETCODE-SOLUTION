class Solution {
public:
    vector<vector<int>> ans;
    void f(int i,int n,int k,vector<int> &a){
        if(a.size()==k){
            ans.push_back(a);
            return ;
        }
        if(i>n) return ;
        a.push_back(i);
        f(i+1,n,k,a);
        a.pop_back();
        f(i+1,n,k,a);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(int i=1; i<=n; i++) nums.push_back(i);
        vector<int> a;
        f(1,n,k,a);
        return ans;
    }
};