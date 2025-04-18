class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        
        //update map with frequency
        for(string &word : words) mp[word]++;
        
        bool centerUsed = false; //for frequency one waale strings
        
        int result = 0;
        
        //start iterating on words one by one
        for(string &word : words) {
            string rev = word;
            reverse(begin(rev), end(rev));
            
            if(rev != word) { //"ab" "ba"    ->.  {ab      ba}
                if(mp[word] > 0 && mp[rev] > 0) {
                    mp[word]--;
                    mp[rev]--;
                    result += 4;
                }
            } 
            
        //else case => for word with same character and check it's frequency for >=2 and if present then it 
        //can contribute for 4 length ex=> word ="aa" and rev="aa" , resultant will be "aaaa" of 4 length
            else {
                if(mp[word] >= 2) {
                    mp[word] -= 2;
                    result += 4;
                } 
                else if(mp[word] == 1 && centerUsed == false) {
                    mp[word]--;
                    result += 2;
                    centerUsed = true; //ab use hogaya hai center wala
                }
            }
        }
        
        return result;
    }
};