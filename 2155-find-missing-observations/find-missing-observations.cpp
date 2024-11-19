class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        int m=rolls.size();
        int sum=0;
        for(int i=0; i<m; i++) sum+=rolls[i];
        int rem_mean=(mean*(n+m)) - sum;

        int can_be_made=n*6;
        if(rem_mean < n || rem_mean > can_be_made) return ans;
        while(n>0 and rem_mean>0){
            int remainder=rem_mean%n;
            int quotient=rem_mean/n;

            ans.push_back(quotient);
            rem_mean=rem_mean-quotient;
            n--;
        }
        return ans;
    }
};