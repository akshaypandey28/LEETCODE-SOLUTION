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

/* 
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string temp = "";

        string result = "";
        //By default stringstream breaks on ' ' (space character)
        while(ss >> temp) {
            result = temp + " " + result;
        }

        return result.substr(0, result.length()-1);  //to remove the last space
    }
};
 */