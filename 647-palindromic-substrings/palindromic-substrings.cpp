class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        int n=s.size();
        for(int i=0; i<n; i++){
            //expand around center but for even case
            int low=i-1;
            int high=i;
            while(low>=0 and high<n and s[low]==s[high]){
                count++;
                low--;
                high++;
            }
            //expand around center but for odd case
            low=i-1;
            high=i+1;
            count++;
            while(low>=0 and high<n and s[low]==s[high]){
                count++;
                low--;
                high++;
            }
        }
        return count;
    }
};