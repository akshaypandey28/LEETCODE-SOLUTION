class Solution {
public:
    //int ans;
    vector<vector<int>> dp;
    int f(vector<int> &nums,int i,int pi){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][pi+1]!=-1) return dp[i][pi+1];
        int take=0,nottake=0;
        if(pi==-1 || nums[i]>nums[pi]){
            take=1+f(nums,i+1,i);
        }
        nottake=0+f(nums,i+1,pi);
        return dp[i][pi+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.clear();
        int n=nums.size();
        dp.resize(n, vector<int>(n+1, -1));
        //int temp=1;
        int res=f(nums,0,-1);
        return res;

    }
};