#define pp pair<int,int>
class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[0]<b[0];
    }
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        priority_queue<pp, vector<pp>, greater<pp> > occupied; //{departTime, chairNo}
        priority_queue<int, vector<int>, greater<int>> free; //min heap of free chair
        int targetFriendArrival = times[targetFriend][0];
        sort(times.begin(),times.end(),cmp);
        int chairNo=0;
        for(int i = 0; i < n; i++) {
            int arrival  = times[i][0];
            int depart   = times[i][1];
            
            //free chairs accordingly
            while(occupied.empty()!=1 && occupied.top().first <= arrival) {
                free.push(occupied.top().second); //this chair is now free
                occupied.pop();
            }

            if(free.empty()) { //empty hai 
                occupied.push({depart, chairNo});

                if(arrival == targetFriendArrival)
                    return chairNo;

                chairNo++;
            } else { //empty nhi hai
                int leastChairAvailable = free.top();
                free.pop();
                if(arrival == targetFriendArrival) {
                    return leastChairAvailable;
                }
                occupied.push({depart, leastChairAvailable});
            }
        }

        return -1;
    }
};