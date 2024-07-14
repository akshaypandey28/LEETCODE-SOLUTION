class Solution {
public:
    vector<string> ans;
    set<string> st;
    vector<int> dp;
    void f(string s,int i,vector<string> str){
        if(i==s.size()) {
            string a;
            for(int i=0; i<str.size()-1; i++){
                a+=(str[i]+" ");
            }
            a+=(str[str.size()-1]);
            ans.push_back(a);
            return ; 
        }
        //if(dp[i]!=-1) return dp[i];
        string temp;
        for(int j=i; j<s.size(); j++){
            temp+=s[j];
            if(st.find(temp)!=st.end()){
                str.push_back(temp);
                 f(s,j+1,str);// ) //return dp[i]= 1; //true 
                str.pop_back();
            } 
        }
        //return dp[i]=0; //false
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dp.clear();
        dp.resize(305,-1);
        for(auto ele:wordDict) st.insert(ele);
        vector<string> str;
        f(s,0,str);
        return ans;
    }
};