class Solution {
public:
    bool detectCapitalUse(string word) {
        int countCapitals = 0;
        
        for(char &ch : word) {
            if(isupper(ch)) countCapitals++;
        }
        
        if(countCapitals == 0) return true; //means all are small
        
        if(countCapitals == word.length()) return true; //means all are capital
        
        if(countCapitals == 1 && isupper(word[0])) return true;
        //means first word is capital and rest are small
        
        return false;
        
    }
};