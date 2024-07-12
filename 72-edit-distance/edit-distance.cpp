class Solution {
public:
    vector<vector<int>> dp;
    int f(string word1, string word2,int i,int j){
        if(i == word1.size()) return word2.size() - j; // Return the remaining characters of word2 means addition in word1
        if(j == word2.size()) return word1.size() - i; //deletion of word1 characters
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=f(word1,word2,i+1,j+1);
        }
        return dp[i][j]=1+min( { f(word1,word2,i+1,j+1), f(word1,word2,i+1,j), f(word1,word2,i,j+1) }       );

        //f(word1,word2,i+1,j+1)  for replace a character
        //f(word1,word2,i+1,j) for delete 
        //f(word1,word2,i,j+1) for insertion
    }
    int minDistance(string word1, string word2) {
        dp.clear();
        dp.resize(505,vector<int>(505,-1));
        return f(word1,word2,0,0);
    }
};