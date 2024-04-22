class Solution {
public:
    vector<int> dp;
    int numTrees(int n) {
        dp.clear();
        dp.resize(30, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        //f(n) nikalna hai to f(n-1) f(n-2) etc sare answer hone chahiye
        for(int i = 3; i <= n; i++) { // order
            // f(i)
            for(int k = 1; k <= i; k++) {
            // k -> potential root
                dp[i] += dp[k-1]*dp[i-k];
            }
        }
        return dp[n];
    }
};
/* 
class Solution {
public:
    vector<int> dp;
    int f(int i) {
        if(i == 0 or i == 1) return 1;
        if(i == 2) return 2;
        if(dp[i] != -1) return dp[i];
        int sum = 0;
        for(int k = 1; k <= i; k++) { //this loop is for because when i=3 comes then i need to make root from 
            //1 to i that is upto 3
            // k -> potential root
            sum += f(k-1)*f(i-k);
        }
        return dp[i] = sum;
    }
    int numTrees(int n) {
        dp.clear();
        dp.resize(30, -1);
        return f(n);
    }
};
 */