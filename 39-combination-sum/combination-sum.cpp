class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>& candidates,vector<int> v,int target,int i){
        if(target==0){
            ans.push_back(v);
            return ;
        }

        if(i==candidates.size()) return ;

        if(target<0) return ;

        if(candidates[i] <= target) {
            v.push_back(candidates[i]);


            f(candidates,v,target-candidates[i],i); //pick case when candidates[i] <= target
            //i+1 ke jgh i hai because next element pr jana mandatory nhi hai same element ko bar bar pick kiya ja skta hai
            //jb tk element ko na pick krne wali state na aa jaye
            
            v.pop_back();
        }
        
        f(candidates,v,target,i+1); //not pick case when candidates[i] <= target and for greater value than candidates[i]
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        ans.clear();
        f(candidates,v,target,0);
        
        return ans;
    }
};