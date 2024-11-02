//1st method top down solution
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
    }
};