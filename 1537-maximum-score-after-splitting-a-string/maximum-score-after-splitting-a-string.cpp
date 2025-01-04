class Solution {
public:
    int maxScore(string s) {
        vector<int> prefix;
        int count=0;
        for(char c:s){
            if(c=='0') count++;
            prefix.push_back(count);
        }
        int ans=0;
        int ones=0;
        for(int i=s.size()-1; i>=1; i--){
            if(s[i]=='1') ones++;
            ans=max(ans,ones+prefix[i-1]);
        }
        return ans;
    }
};