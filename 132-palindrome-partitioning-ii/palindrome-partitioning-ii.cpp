class Solution {
public:
    vector<int> dp;
    bool palindrome(string &s, int start, int end){//function for checking the palindrome
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    int f(string &s,int i){
        if (i == s.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int ans=INT_MAX;
        for(int j=i; j<s.size(); j++){
            if(palindrome(s,i,j)){
                int cost= 1 + f(s,j+1);
                ans=min(ans,cost);
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        dp.clear();
        dp.resize(n,-1);
        return f(s,0) - 1; //-1 because function calculates the total number of palindrome substring in minimum 
//but the answer is total number of partitioning can be done
    }
};