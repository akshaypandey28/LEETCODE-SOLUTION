class Solution {
public:
    int partitionString(string s) {
        int ans=0;
        unordered_set<char> seen; 
        for(char ch:s){
            if(seen.find(ch)!=seen.end()){
                ans++;
                seen.clear();
            }
            seen.insert(ch);
        }
        if(seen.size()!=0) ans++;
        return ans;
    }
};