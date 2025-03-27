class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> sortedStart;
        for (string& word : startWords) {
            sort(word.begin(), word.end());
            sortedStart.insert(word);
        }

        int ans = 0;
        for (string& word : targetWords) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            for (int i = 0; i < sortedWord.size(); i++) {
//For each targetWord, remove one character at a time and check if the remaining string (sorted) exists in the set of startWords
                string candidate = sortedWord.substr(0, i) + sortedWord.substr(i + 1); 
    //16th line is removal of one character that is ith character 
                if (sortedStart.count(candidate)) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};