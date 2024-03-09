class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        if(n==1) return 1;
        map<char,int> m;
        for(int i=0; i<n; i++) m[s[i]]++;
        int ans=0;
        bool flag=false;
        for(auto ele:m){
            if(ele.second%2==0) ans+=ele.second;
            else {
                ans+=ele.second-1;
                flag=true;
            }
        }
        if(flag)  ans++;
        return ans;
    }
};