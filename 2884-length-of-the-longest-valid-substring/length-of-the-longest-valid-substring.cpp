/* Approach : Sliding Window
1. Store all forbidden words in unordered set.
2. Use sliding window to find max length of valid substring
Time : O(m * maxLen + n * (maxLen^2))       // set + Sliding Window         
Space : O(m * maxLen + n * maxLen )         // set + temp string
where, n = word.size(), m = forbidden.size(), maxLen = Max length of any forbidden word
*/

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        // store forbidden words in set
        int maxLen = 0;
        unordered_set<string> st;
        for(auto s : forbidden){
            st.insert(s);
            maxLen = max(maxLen, (int)s.size());
        }

        // sliding window
        int n = word.size();
        int ans = 0;
        int l = 0, r = 0;
        while(r < n){
            // check for forbidden substrings after including l in current window
            string temp;
            for(int i=r; (i >= l) && (i > r-maxLen); i--){      // need to check only upto maxLen
                temp = word[i] + temp;
                if(st.count(temp)){         // temp present in forbidden words
                    l = i+1;                // ith char can't be present in valid window, update 
                    break;
                }
            }
            ans = max(ans, r-l+1);            // update ans for current window
            r++;                            // slide right boundary for next iteration
        }
        return ans;
    }
    
};