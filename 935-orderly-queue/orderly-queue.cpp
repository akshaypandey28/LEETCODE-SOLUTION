//if there is freedom of swaping two characters in string then the string can be sorted
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1) {
            sort(begin(s), end(s));
            return s;
        }
        
        string result = s;
        for(int i = 1; i<s.length(); i++) {
            string temp = s.substr(i) + s.substr(0, i);
            result = min(result, temp);
        }
        
        return result;
    }
};