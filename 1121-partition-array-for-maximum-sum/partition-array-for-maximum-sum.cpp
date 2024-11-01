class Solution {
public:
    vector<int> dp;
    int n;
    int f(vector<int> &arr,int k,int i){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MIN; //this keep the track of maximum answer that can be calculated
        int maxi=INT_MIN;
        int len=0;
        for(int j=i; j<min(i+k,n); j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=maxi*len + f(arr,k,j+1);
            ans=max(ans,sum);
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.clear();
        n=arr.size();
        dp.resize(n+1,-1);
        return f(arr,k,0);
    }
};