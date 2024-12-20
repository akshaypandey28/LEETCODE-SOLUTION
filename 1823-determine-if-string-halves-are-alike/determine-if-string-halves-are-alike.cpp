class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        int count=0;
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);  //transform(first, last, result, func)

        for(int i=0; i<n/2; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') count++;
        }
        for(int i=n/2; i<n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') count--;
        }
        return count==0;
    }
};