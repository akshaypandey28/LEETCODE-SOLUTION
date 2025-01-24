class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count_L=0,count_R=0,count_space=0;
        for(int i=0; i<moves.size(); i++){
            if(moves[i]=='L') count_L++;
            else if(moves[i]=='R') count_R++;
            else count_space++;
        }

        int ans=max(count_L,count_R)+count_space - min(count_L,count_R);
        return ans;
    }
};