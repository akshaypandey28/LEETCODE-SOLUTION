class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        vector<int> ans;
        int left=0;
        int right=v[0].size()-1;
        int top=0; 
        int bottom=v.size()-1;
        int direction=0;
        while(left<=right and top<=bottom){
            
            if(direction==0){ //left to right
                for(int j=left; j<=right; j++) ans.push_back(v[top][j]);
                top++;
            }
            else if(direction==1){  // top to bottom
                for(int i=top; i<=bottom; i++) ans.push_back(v[i][right]);
                right--;
            }
            else if(direction==2){  //right to left
                for(int j=right; j>=left; j--) ans.push_back(v[bottom][j]);
                bottom--;
            }
            else if(direction==3){ //bottom to top
                for(int i=bottom; i>=top; i--) ans.push_back(v[i][left]);
                left++;
            }
            direction= (direction+1)%4;//because direction should be in the range of 0(including)to 4(leave it)i.e.0,1,2,3
        }
        return ans;
    }
};