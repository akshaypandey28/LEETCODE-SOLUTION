class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tot =0, mid =0,in=0;
        for(int i =0 ;i < n ; i++){
            tot += gas[i]-cost[i]; //it is used for tracking that is when the loops completes if it is possible 
            //to reach at every station then total>=0 else <0 
            mid += gas[i]-cost[i]; //used for determing whether current station can be used for starting point or not
            //is mid < 0 then current station cann't be used for starting point that means there can be chance that next 
            //station can be used for the starting point that is i+1
            if(mid<0){
                mid = 0;
                in = i+1;
            }
        } 
        if(tot<0) return -1;
        else return in;
    }
};