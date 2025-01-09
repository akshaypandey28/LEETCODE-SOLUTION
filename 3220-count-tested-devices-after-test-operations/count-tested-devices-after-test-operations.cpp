//self
class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        //i calculate how many times i reach at every index so 
        //if idx=1 then no. of reach=(idx+1)

        int prefix=0; //used for checking for every idx can become the part of the answer or not
        //if the idx = 4 then prefix have the sum till idx-1 i.e 3
        int count=0;
        for(int i=0; i<batteryPercentages.size(); i++){
            if(batteryPercentages[i]-prefix > 0){
                count++;
                prefix++;
            }
        }
        return count;
    }
};