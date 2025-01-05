class Solution {
public:
    int partitionString(string s) {
        int ans=0;
        string temp="";
        for(char ch:s){
            if(temp.find(ch)!=-1){
                temp="";
                ans++;
                temp.push_back(ch);
            }
            else temp.push_back(ch);
        }
        if(temp.size()!=0) ans++;
        return ans;
    }
};