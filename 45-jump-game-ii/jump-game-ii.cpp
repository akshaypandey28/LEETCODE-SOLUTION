class Solution {
public:
    vector<int> dp;
    int f(vector<int> &nums,int n){
        for(int i=n-3; i>=0; i--){
            if(nums[i]>=(n-1-i))  dp[i]=1;
            else if(nums[i]==0) continue;
            else{
                int temp=nums[i]; //for traversing the number of steps
                int j=i+1; //it is used for checking the value of dp from i+1
                int ans=INT_MAX; //used to store the min steps from any point
                int idx=j;
                while(temp--){
                    if(dp[j]==0) {
                        j++;
                        continue;
                    }
                    if(dp[j]!=0){
                        if(ans>dp[j]){
                            ans=min(ans,dp[j]);
                            idx=j;
                        }
                    }
                    j++;
                }
                if(ans<INT_MAX) dp[i]=ans+1;
            }
        }
        return dp[0];
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        dp.clear();
        dp.resize(10005,0);
        dp[n-1]=0;
        if(nums[n-2]>=1) dp[n-2]=1;
        
        int ans= f(nums,n);
        for(int i=0; i<n; i++) cout<<dp[i]<<" ";
        return ans;
    }
};