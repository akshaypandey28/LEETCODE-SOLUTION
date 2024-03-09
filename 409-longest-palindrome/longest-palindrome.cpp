class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        if(n==1) return 1;
        map<char,int> m;
        for(int i=0; i<n; i++) m[s[i]]++;
        multiset<int> odd_count;//this keeps the track of odd numbers not duplicate
        int ans=0;
        for(auto ele:m){
            if(ele.second%2==0) ans+=ele.second;
            else odd_count.insert(ele.second);
        }
        vector<int> a;
        
        for(auto ele:odd_count) a.push_back(ele);
        for(int i=0; i<a.size(); i++){
            if(i==0) ans+=a[i];
            else ans+=a[i]-1;
        }
        return ans;
    }
};