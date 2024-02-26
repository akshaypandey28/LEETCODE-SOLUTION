class Solution {
public:
    vector<vector<string>> ans;
    bool palindrome(string s, int start, int end){//function for checking the palindrome
        
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void f(string s,int idx,vector<string>&path){
        if(idx==s.size()){
            ans.push_back(path);
            return ;
        }
        for(int i=idx; i<s.size(); i++){
            if(palindrome(s,idx,i)){
                path.push_back(s.substr(idx, i - idx + 1));
                f(s,i+1,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>path;
        f(s,0,path);
        return ans;
    }
};