class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() == 1)  return true;
        unordered_map<char, int> map;
        for (int i = 0; i < order.size(); i++) map[order[i]] = i;

        for (int i = 0; i < words.size() - 1; i++) {
            // Traverse each character in a word
            for (int j = 0; j < words[i].size(); j++) {
                // If all the letters have matched so far, but the current word is longer than the next one, 
                //the two are not in order and we return False
                if (j >= words[i + 1].size()) return false;
                // Check if the letters in the same position in the two words are different
                if (words[i][j] != words[i + 1][j]) {
                    // Check if the rank of the letter in the current word is greater than the rank in the same 
                    // position in the next word
                    if (map[words[i][j]] > map[words[i + 1][j]]) return false;

                    //else => if we find the first different character and they are sorted, then there's no need to 
                    // check remaining letters
                    else break;
                }
            }
        }
        return true;
    }
};