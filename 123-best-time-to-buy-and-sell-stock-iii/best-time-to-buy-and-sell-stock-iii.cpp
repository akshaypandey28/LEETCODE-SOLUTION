class Solution {
public:
    int dp[100005][10][2]; 
    int profit(vector<int> &prices,int i,int k,bool on){
        if(i==prices.size()) return 0;
        if(dp[i][k][on]!=-1) return dp[i][k][on];

        int ans=INT_MIN;
        ans=profit(prices,i+1,k,on); //avoid case 
        if(on==true){ 
            ans=max(ans,prices[i]+profit(prices,i+1,k-1,false)); //not avoid 
        }
        else{ //on==false
            if(k>0){
                ans=max(ans,profit(prices,i+1,k,true)-prices[i]); //not avoid and there is no previous txn
                //which is ongoing
            }
        }

        return dp[i][k][on]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return profit(prices,0,2,false); //here k is fixes that is 2 but in fourth problem of same question 
        //k can be any integer means same solution of both problem
    }
};