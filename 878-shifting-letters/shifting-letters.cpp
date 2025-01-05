//self and do dry run
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        vector<int> suffix(n);
        suffix[n - 1] = shifts[n - 1] % 26; // Modulo 26 to handle overflow
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = (shifts[i] + suffix[i + 1]) % 26; // Cumulative sum with modulo
        }

        for (int i = 0; i < s.size(); i++) {
            int newChar = (s[i] - 'a' + suffix[i]) % 26; // Calculate shifted character
            s[i] = 'a' + newChar; // Map back to character
        }

        return s;
    }
};