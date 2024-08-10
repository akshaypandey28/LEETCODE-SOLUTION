class Solution {
public:
    bool judgeCircle(string moves) {
        int y=0;//for up and down
        int x=0;//for left and right
        for(char ch:moves){
            if(ch=='U') y++;
            else if(ch=='D') y--;
            else if(ch=='R') x++;
            else x--;
        }
        if(x==0 and y==0) return true;
        return false;
    }
};