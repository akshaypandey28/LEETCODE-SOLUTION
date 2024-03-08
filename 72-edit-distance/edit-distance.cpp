class Solution {
public:
    vector<vector<int>> dp;
    int f(string word1, string word2,int i,int j){
        if(i == word1.size()) return word2.size() - j; // Return the remaining characters in word2
        if(j == word2.size()) return word1.size() - i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=0+f(word1,word2,i+1,j+1);
        }
        return dp[i][j]=1+min(f(word1,word2,i+1,j+1),
        min(    f(word1,word2,i+1,j),    f(word1,word2,i,j+1)    )     );
    }
    int minDistance(string word1, string word2) {
        dp.clear();
        dp.resize(505,vector<int>(505,-1));
        return f(word1,word2,0,0);
    }
};