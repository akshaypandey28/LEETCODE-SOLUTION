class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec(n,vector<int>(n));
        int left=0;
        int right=vec[0].size()-1;
        int top=0; 
        int bottom=vec.size()-1;
        int dir=0;
        int val=1;
        while(left<=right and top<=bottom){
            if(dir==0){
                for(int i=left; i<=right; i++) vec[top][i]=val++;
                top++;
            }
            else if(dir==1){
                for(int i=top; i<=bottom; i++) vec[i][right]=val++;
                right--;
            }
            else if(dir==2){
                for(int i=right; i>=left; i--) vec[bottom][i]=val++;
                bottom--;
            }
            else {
                for(int i=bottom; i>=top; i--) vec[i][left]=val++;
                left++;
            }
            dir++;
            if(dir%4==0) dir=0;
        }
        return vec;
    }
};