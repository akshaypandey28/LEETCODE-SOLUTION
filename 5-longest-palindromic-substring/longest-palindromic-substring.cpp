class Solution {
public:
    void f(string s,string &ans){
        int maxLength=1;
        int len=s.size(), start=0;
        int low,high;
        for(int i=0; i<len; i++){
            low=i-1;
            high=i;
            while(low>=0 and high<len and s[low]==s[high]){ //this loop runs for a substring with two characters equal and checking
            //along it's left and right
                if(high-low+1 > maxLength){
                    start=low;
                    maxLength=high-low+1;
                }
                low--;
                high++;
            }
            low=i-1;
            high=i+1;
            while(low>=0 and high<len and s[low]==s[high]){//this loop runs for a substring with a character be a center position 
            //and checking along it's left and right
                if(high-low+1 > maxLength){
                    start=low;
                    maxLength=high-low+1;
                }
                low--;
                high++;
            }
        }
        for(int i=start; i<=start+maxLength-1; i++){
            ans.push_back(s[i]);
        }
    }
    string longestPalindrome(string s) {
        string ans="";
        f(s,ans);
        return ans;
    }
};