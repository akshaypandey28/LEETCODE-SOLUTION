class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;
    void f(vector<int> &nums,int i,vector<int> v,int n){
        if(i==n){
            s.insert(v);
            return ;
        }
        v.push_back(nums[i]);
        f(nums,i+1,v,n);
        v.pop_back();
        f(nums,i+1,v,n);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(),nums.end());
        f(nums,0,v,nums.size());
        for(auto ele:s){
            ans.push_back(ele);
        }
        return ans;
    }
};