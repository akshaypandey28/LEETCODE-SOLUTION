class Solution {
public:
    int minimumLength(string s) {
        int l=0,h=s.size()-1;
        while(l<h){
            if(s[l]==s[h]){
                l++;
                h--;
                while(s[l]==s[l-1] and l<h-1) l++;
                while(s[h]==s[h+1] and l<h-1) h--;
            }
            else break;
        }
        return h-l+1;
    }
};