//Approach-2 
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> startEnd(n+1, 0); //because garden have 0 to n points so i have to calculate for every points
        
        for(int i = 0; i<ranges.size(); i++) {
            int start = max(0, i-ranges[i]);
            int end = min(n, i+ranges[i]);
            
            startEnd[start] = max(startEnd[start], end); //from start, that's farthest I can jump to right
        }
        
      
        int currEnd  = 0;
        int maxReach = 0;
        int count    = 0;
        for(int i = 0; i<=n; i++) {

            if(i>maxReach) return -1;
            
            if(i>currEnd) {
                count++;
                currEnd=maxReach;
            }
            
            maxReach=max(maxReach,startEnd[i]);
        }
        return count;
    }
};