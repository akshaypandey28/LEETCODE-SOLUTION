class Solution {
public:
//i used for target and j used for word traversing
    vector<vector<int>> dp;
    int m;
    int MOD=1e9+7;
    int solve(int i,int j,vector<vector<long long>> &freq,string &target){
        if(i==target.size()) return 1;
        if(j==m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int not_take=solve(i,j+1,freq,target)%MOD;
        
        int take=(freq[target[i]-'a'][j] * solve(i+1,j+1,freq,target))%MOD; 
        //if target[i]==word[j] means character matches
        //take ka use krke answer compute hoga 
        //take includes both take and not_take
        //and not_take is already defined 

        return dp[i][j]=(take+not_take)%MOD;
       
    }
    int numWays(vector<string>& words, string target) {
        m=words[0].size();
        vector<vector<long long>> freq(26,vector<long long> (m,0)); //gives the frequency of each 
        //character for at index

        for(string word:words){
            for(int col=0; col<m; col++){
                freq[word[col]-'a'][col]++;
                //freq[word[i]-'a'] represents a character
            }
        }

        dp.clear();
        dp.resize(1005,vector<int>(10005,-1));

        return solve(0,0,freq,target); 
    }
};