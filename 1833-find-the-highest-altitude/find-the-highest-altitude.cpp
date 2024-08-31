class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        int prev=0;
        for(int i=0; i<gain.size(); i++){
            //altitude calculation
            int altitude=gain[i]+prev; //alt[i]=gain[i-1]+alt[i-1]
            //example gain[0]=alt[1]-alt[0] => alt[1]=gain[0]+alt[0] and alt[0]=0
            maxi=max(altitude,maxi);
            prev=altitude;
        }
        return maxi;
    }
};