class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>& candidates,vector<int> v,int target,int i,int sum){
        if(sum==target){
            ans.push_back(v);
            return ;
        }

        if(i==candidates.size()) return ;

        if(sum>target) return ;

        if(candidates[i] <= target) {
            v.push_back(candidates[i]);
            sum+=candidates[i];
            f(candidates,v,target,i,sum); //pick case when candidates[i] <= target
            //i+1 ke jgh i hai because next element pr jana mandatory nhi hai same element ko bar bar pick kiya ja skta hai
            //jb tk element ko na pick krne wali state na aa jaye
            sum-=candidates[i];
            v.pop_back();
        }
        //avoid
        int j=i+1;
        
        f(candidates,v,target,j,sum); //not pick case when candidates[i] <= target and for greater value than candidates[i]
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        ans.clear();
        sort(candidates.begin(),candidates.end());
        f(candidates,v,target,0,0);
        
        return ans;
    }
};