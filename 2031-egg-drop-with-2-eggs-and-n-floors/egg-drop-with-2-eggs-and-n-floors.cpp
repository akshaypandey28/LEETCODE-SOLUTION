class Solution {
public:
    //find minimum number of moves in worst case is 1 + max(solve(e-1,k-1) , solve(e,f-k))
    vector<vector<int>> dp;
    int solve(int f,int e){ // here f is total no. of floor
        if(e==1) return f;
        if(f==1 || f==0) return f;
        if(dp[f][e]!=-1) return dp[f][e];

        int ans=INT_MAX;
        for(int k=1; k<=f; k++){
            int temp=1+max(solve(k-1,e-1) , solve(f-k,e));
            ans=min(ans,temp);
            //first one is egg break then reduce the number of floor that is move down
            //second one is egg doesn't break then move up
        }
        return dp[f][e]=ans;
    }
    int twoEggDrop(int n) {
        dp.clear();
        dp.resize(n+1,vector<int>(3,-1)); //here 3 is for eggs that is 0 1 2 eggs colums
        return solve(n,2);
    }
};