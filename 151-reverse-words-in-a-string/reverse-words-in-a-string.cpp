class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        reverse(s.begin(),s.end());
        for(char c:s){
            if(c==' '){
                if(temp.size()!=0){
                    ans=temp+" "+ans;
                    temp="";
                }
            }
            else temp.push_back(c);
        }
        if(temp.empty()!=1) ans=temp+" "+ans;
        ans.pop_back(); //to remove the last space
        reverse(ans.begin(),ans.end());
        return ans;
    }
};