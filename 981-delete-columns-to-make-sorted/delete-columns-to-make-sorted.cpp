class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(); //row
        int m=strs[0].size(); //column

        //i must have to check for all the column so 
        //first loop is for column and second loop is for row
//   0 1 2 => column
// 0 a b c
// 1 b c e
// 2 c a e
        int count=0;
        for(int j=0; j<m; j++){
            for(int i=1; i<n; i++){
                if(strs[i][j]<strs[i-1][j]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};