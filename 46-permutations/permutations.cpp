class Solution {
public:
void per(vector<vector<int>> &ans,int i,vector<int> &nums){
    if(i==nums.size()){
        ans.push_back(nums);
        return ;
    }
    for(int j=i; j<nums.size(); j++){
        swap(nums[i],nums[j]);
     
        per(ans,i+1,nums);

        swap(nums[i],nums[j]);
    }
    
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        //vector<int> a;
        per(ans,0,nums);
        return ans;
    }
};