#define ll long long int
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<ll,ll> > dp(n);
        ll ans=0;
        for(int i=1; i<n; i++){
            for(int j=0; j<=i-1; j++){
                ll diff=(ll)nums[i]-(ll)nums[j];
                if(dp[j].find(diff)!=dp[j].end()){
                    //found the element
                    ans+=dp[j][diff];
                }
                dp[i][diff]+=dp[j][diff]+1;
            }
        }
        return (int)ans;
    }
};