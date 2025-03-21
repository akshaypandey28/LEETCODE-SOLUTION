//Approach - Greedily moving ahead
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        
        int time    = 0;
        int prevMax = 0; //jb new balloon pr reach krenge tb prevMax 0 se update hoga because ab new 
        //balloon mil chuka hai
        
        for(int i = 0; i<n; i++) {
            
            if(i > 0 && colors[i] != colors[i-1]) prevMax = 0;
            
            int curr = neededTime[i];
            
            time += min(prevMax, curr); //greedily
            
            prevMax = max(prevMax, curr);
            
        }
        
        return time;
    }
};