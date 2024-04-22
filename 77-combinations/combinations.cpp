class Solution {
public:
    vector<vector<int>> ans;
    void f(int i,vector<int> &nums,int k,vector<int> &a){
        if(a.size()==k){
            ans.push_back(a);
            return ;
        }
        if(i==nums.size()) return ;
        a.push_back(nums[i]);
        f(i+1,nums,k,a);
        a.pop_back();
        f(i+1,nums,k,a);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(int i=1; i<=n; i++) nums.push_back(i);
        vector<int> a;
        f(0,nums,k,a);
        return ans;
    }
};