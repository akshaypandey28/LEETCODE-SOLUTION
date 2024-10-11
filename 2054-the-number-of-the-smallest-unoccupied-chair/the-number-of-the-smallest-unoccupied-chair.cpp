class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[0]<b[0];
    }
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int targetArrivalTime = times[targetFriend][0];
        sort(times.begin(),times.end(),cmp);
        int n=times.size();
        vector<int> occupied(n,0); //at max we will have 0 to n-1 chairs
        /* We need to sort the times based on arrival time but we don't want to
            loose the friend number after sorting. So, store the arrival time
            of targetFriend because it's given in the question that 
            Each arrival time is distinct. */
        
        for(vector<int> &time : times) {
            int arrival = time[0];
            int depart  = time[1];
            //Find the first unoccupied chair
            for(int i = 0; i<n; i++) {
                if(occupied[i] <= arrival) {
                    occupied[i] = depart; //update with current friend depart time
                    if(arrival == targetArrivalTime)
                        return i;
                    break;
                }
            }
        }
        return -1;
    }
};