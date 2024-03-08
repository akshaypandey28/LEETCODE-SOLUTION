class Solution {
public:
    vector<bool> dp;
    bool f(vector<int> &nums,int n){
        for(int i=n-3; i>=0; i--){
            if(nums[i]>=(n-1-i))  dp[i]=true;
            else{
                int temp=nums[i];
                int j=i+1;
                while(temp--){
                    if(dp[j]==true){
                        dp[i]=true;
                        break;
                    }
                    j++;
                }
            }
        }
        return dp[0];
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        dp.clear();
        dp.resize(10005,0);
        dp[n-1]=1;
        if(nums[n-2]>=1) dp[n-2]=1;
        return f(nums,n);
    }
};