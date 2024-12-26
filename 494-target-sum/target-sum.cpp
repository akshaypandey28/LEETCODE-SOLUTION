class Solution {
public:
    int mod =(int)1e9+7;
    int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector
<int>> &dp){

     if(ind == arr.size()){
        if(target==0) return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = countPartitionsUtil(ind+1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = countPartitionsUtil(ind+1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken)%mod;
}
    int findTargetSumWays(vector<int>& arr, int d) { //d is target
        int n=arr.size();
        int totSum = 0;
        for(int i=0; i<arr.size();i++){
            totSum += arr[i];
        }
        //s1-s2=d and s1=totalsum-s2
        //totalsum-s2-s2=d ,=>  s2=(totalsum-d)/2
        //means s2 can't be negative and can't be decimal number
        //Checking for edge cases
        if(totSum-d<0) return 0;
        if((totSum-d)%2==1) return 0;
        
        int s2 = (totSum-d)/2;
        
        vector<vector<int>> dp(n,vector<int>(s2+1,-1));
        return countPartitionsUtil(0,s2,arr,dp);
    }
};