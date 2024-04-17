class Solution {
public:
    vector<vector<int> > dp;
    bool f(vector<int> &arr,int i,int sum){
        if(sum==0) return true; //agr sum 0 ho gya to elements bache ho ya na bache ho answer true hoga
        if(i==arr.size()) return false; //agr sum 0 nhi hua aur i arr.size() ke equal ho gya to answer false hoga
        if(dp[i][sum]!=-1) return dp[i][sum];
        if(arr[i]<=sum){
            //we can include or exclude
            return dp[i][sum] = f(arr,i+1,sum-arr[i]) or f(arr,i+1,sum);
        }
        else{
            //always exclude
            return dp[i][sum] = f(arr,i+1,sum);
        }
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for(int i=0; i<nums.size(); i++) s+=nums[i];
        if(s%2!=0) return false;
        dp.clear();
        dp.resize(205, vector<int> (20005, -1));
        return f(nums,0,s/2); //i am passing half of the total sum to check whether it is possible to create a subset or not




        //optimized solution 

        // int k = s/2; //k is half of the total sum
        // for(int i = 0; i < n; i++) dp[i][0] = true; // base case
        // for(int i = n-1; i >= 0; i--) {
        //     for(int j = 1; j <= k; j++) {
        //         if(nums[i] <= j)
        //             dp[i][j] = dp[i+1][j-nums[i]] or dp[i+1][j];
        //         else {
        //             dp[i][j] = dp[i+1][j];
        //         }
        //     }
        // }
        // return dp[0][k];
    }
};