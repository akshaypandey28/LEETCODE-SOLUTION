class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0,y=0; //current coordinates
        char curr_dir='N';

        for(char ele:instructions){
            if(ele=='G'){
                if(curr_dir=='N') y++;
                if(curr_dir=='S') y--;
                if(curr_dir=='E') x++;
                if(curr_dir=='W') x--;
            }

            else{
                if(curr_dir=='N') curr_dir = ele == 'L' ? 'W' : 'E';
                else if(curr_dir=='S') curr_dir = ele == 'L' ? 'E' : 'W';
                else if(curr_dir=='E') curr_dir = ele == 'L' ? 'N' : 'S';
                else curr_dir = ele == 'L' ? 'S' : 'N'; //curr_dir=='W'
            }
        }

        if(x==0 and y==0) return true;

        if(curr_dir!='N') return true;
        
        return false;
    }
};