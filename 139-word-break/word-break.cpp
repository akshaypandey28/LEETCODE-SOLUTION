class Solution {
public:
    set<string> st;
    vector<int> dp;
    bool f(string s,int i){
        if(i==s.size()) return true;
        if(dp[i]!=-1) return dp[i];
        string temp;
        for(int j=i; j<s.size(); j++){
            temp+=s[j];
            if(st.find(temp)!=st.end()){
                if(  f(s,j+1) ) return dp[i]= 1;
            }
        }
        return dp[i]=0;
    } 
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.clear();
        dp.resize(305,-1);
        for(auto ele:wordDict) st.insert(ele);
        return f(s,0);
    }
};