class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string copy=s+s;
        return copy.substr(1, copy.length()-2).find(s) != -1;
    }
};