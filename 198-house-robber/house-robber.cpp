class Solution {
public:
    vector<int> dp;
    int f(int i,vector<int>& arr){   //TOP TO DOWN
        if( i>=arr.size() )  return 0;

        if(dp[i]!=-1) return dp[i];   

        return dp[i]=max( arr[i]+f(i+2,arr) , f(i+1,arr) );
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size() +10 ,-1);
        return f(0,nums);
    }
};