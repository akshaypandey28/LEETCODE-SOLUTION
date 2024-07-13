class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v={1,2,3,4,5,6,7,8,9};
    void gen(int k,int sum,int i,vector<int> temp){
        if(i==v.size()){
            if(temp.size()==k and sum==0) ans.push_back(temp);

            return ;
        }
        //include
        if(v[i]<=sum){
            temp.push_back(v[i]);
            gen(k,sum-v[i],i+1,temp);
            temp.pop_back();
        }
        //exclude
        gen(k,sum,i+1,temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        //n can act as sum that i have to find for k length array
        vector<int> temp;
        gen(k,n,0,temp);
        return ans;
    }
};