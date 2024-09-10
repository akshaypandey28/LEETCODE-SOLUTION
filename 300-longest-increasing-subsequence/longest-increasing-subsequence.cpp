class Solution {
public:
    vector<int> dp;
    vector<int> arr;
    int f(int i){
        // if(i==0) return 1;
        if(dp[i]!=-1) return dp[i];
        int maxi=INT_MIN;
        for(int j=0; j<=i-1; j++){
            if(arr[j]<arr[i]) maxi=max(maxi,f(j));
        }
        if(maxi==INT_MIN) return dp[i]=1;
        return dp[i]=1+maxi;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        arr=nums;
        dp.clear();
        dp.resize(n+1,-1);
        dp[0]=1;
        int ans=1;
        for(int i=1; i<n; i++){
            ans=max(ans,f(i));
        }
        return ans;
    }
};