//T.C : O(log(columnNumber))
class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string s;
        
        while(columnNumber) {
            columnNumber--; //0 based indexing
            
            int remain = columnNumber%26;
            char ch    = remain + 'A';
            s.push_back(ch);

            columnNumber /= 26;
            
        }
        
        reverse(begin(s), end(s));
        return s;
        
    }
};
