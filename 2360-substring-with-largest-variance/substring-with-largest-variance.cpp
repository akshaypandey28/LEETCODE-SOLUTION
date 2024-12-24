//Approach-1 (Brute Force)
/*
  Find all substrings
  Find max freq and min freq of chars
  result = max(result, max_freq - min_freq)
*/


//Approach-2 (26*26*n)
class Solution {
public:
    int largestVariance(string s) {
        vector<int> count(26, 0);
        
        for(char &ch : s) count[ch-'a']++; //used to check whether the character is present or not in 
        //string        
        
        int result = 0;

        for (char first = 'a'; first <= 'z'; ++first) { //O(26)

            for (char second = 'a'; second <= 'z'; ++second) { //O(26)
                if(first==second) continue;
                if (count[first-'a'] == 0 || count[second-'a'] == 0) continue;


                int firstCount = 0;
                int secondCount = 0;
                bool pastLowFreq = false;

                for (const char& ch : s) {
                    if (ch == first) ++firstCount;
                    if (ch == second) ++secondCount;

                    if (secondCount > 0) //secondCount must be > 0 then the variance can be calculated
                        result = max(result, firstCount - secondCount);
    
                    //else => secondCount==0 i have to check for whether there is second character or not
                    //at (ch-1) idx which contribute for secondCount=1 value
                    //for handling edge case like s="abb"; pastLowFreq term is used and else is used
                    else { 
                        if (pastLowFreq==true) result = max(result, firstCount - 1);
                        //result=max(result,firstCount-secondCount);
                    } 

                    if (secondCount > firstCount) {
                        secondCount = 0;
                        firstCount = 0;
                        pastLowFreq = true;
                    }
                }
            }
        }
        return result;
    }
};