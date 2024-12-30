//Approach-1 (Using Recur + Memo)
//T.C : O(H)
//S.C : O(H)
class Solution {
public:
    int ans;
    int L, H;
    int Z, O;
    const int M = 1e9+7;
    
    int solve(int l, vector<int>& dp) {
        
        if(l > H)
            return 0;
        
        if(dp[l] != -1) return dp[l];
        
        bool addOne = false; //checking for current string length whether it can add 1 in the answer or not
        if(l >= L && l <= H)  addOne = true;
        
        int take_zero = solve(l+Z, dp);
        int take_one  = solve(l+O, dp);
        
        return dp[l] = (addOne + take_zero + take_one)%M;
        
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        ans = 0;
        L = low;
        H = high;
        Z = zero;
        O = one;
        
        vector<int> dp(H+1, -1); //dp[i] = Total number of good strings of length i
        return solve(0, dp);
    }
};


/* //Approach-2 (Bottom Up)
//T.C : O(H)
//S.C : O(H)
class Solution {
public:
    const int M = 1e9+7;
    
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> t(high+1, 0);
        //t[i] = Total number of good strings of length i
        
        t[0] = 1; //Only one good string ""
        
        for(int i = 1; i <= high; i++) {
            
            if(i - zero >= 0)
                t[i] = (t[i]%M + t[i-zero]%M)%M;
            
            if(i - one >= 0)
                t[i] = (t[i]%M + t[i-one]%M)%M;
            
        }
        
        int ans = 0;
        
        for(int l = low; l <= high; l++) {
            ans = (ans%M + t[l]%M)%M;
        }
        
        return ans;
    }
}; */