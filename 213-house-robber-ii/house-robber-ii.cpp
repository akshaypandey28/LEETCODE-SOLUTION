class Solution {
public:
    vector<int> dp;
    int f(int i,vector<int>& arr,int n){   //TOP TO DOWN
        if( i>=n ){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];   }
        return dp[i]=max( arr[i]+f(i+2,arr,n) , f(i+1,arr,n) );
    }
    int rob(vector<int>& nums) {

        dp.resize(nums.size() +10 ,-1);
        int n=nums.size();
        if(n==1) return nums[0];
        //if first house is robbed then last house can't be robbed
        int a=f(0,nums,n-1);
        
        //if first house is not robbed then last house can be robbed
        dp.clear();
        dp.resize(nums.size()+10,-1);
        int b=f(1,nums,n);
        return max(a,b);
    }
};