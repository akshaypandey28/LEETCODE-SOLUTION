class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n=nums.size();
        int pivotId=0,pivotCount=0;
        for(int i=1; i<n; i++){
            if(nums[i-1] > nums[i]){
                pivotId=i;
                pivotCount++;
            }
        }
        if(pivotCount>1) return -1;
        if(pivotCount==0) return 0;

        //pivotCount==1
        return (nums[0] < nums[n-1] ) ? -1 : n-pivotId;
    }
};