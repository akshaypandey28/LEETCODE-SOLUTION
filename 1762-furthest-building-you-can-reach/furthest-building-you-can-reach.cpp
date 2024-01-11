class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq; //such that it keeps the tracks maximum bricks used at one jump
        int i=0;
        int bU=0; //bricksUsed
        for(;i<heights.size()-1; i++){
            if(heights[i] >= heights[i+1]) continue;
            int heightDiff=heights[i+1]-heights[i];
            if(heightDiff + bU <= bricks) { //do we have enough bricks
                pq.push(heightDiff);
                bU=bU + heightDiff;
            }
            else if(ladders > 0) {
                if(pq.empty()!=1 and pq.top() > heightDiff ){
                    bU=bU-pq.top() + heightDiff;
                    pq.pop();
                    pq.push(heightDiff);
                }
                ladders--; //ladders use hona hi hai agr if condition execute hua then piche jha pr bricks 
//use hua tha wha pr ladder use krna hai aur agr execute nhi hua tb bhi ladder execute krna hai
            }
            else{
                    break;
                }
        }
        return i;
    }
};