class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        if(r==0){
            return false;
        }
        int c=matrix[0].size();
        int lo=0, hi=r*c-1;
        int midElement,midIdx;
        while(lo<=hi){
            int mid=lo + (hi-lo)/2;
            midElement=matrix[mid/c][mid%c];

            if(midElement==target)return true;

            else if(midElement<target)  lo=mid+1;

            else hi=mid-1;
        }
        return false;
    }
};