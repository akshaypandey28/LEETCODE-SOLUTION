class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){ //here a and b is a array
        return a[1]<b[1];
    }
    static bool cp(vector<int> a,vector<int> b){ //here a and b is a array
        return a[0]<b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //1st method by sorting in increasing order of end time
        sort(intervals.begin(),intervals.end(),cmp);
        vector<int> lastPicked=intervals[0]; //this is also a array
        int count=0;
        for(int i=1; i<intervals.size(); i++){
            if(lastPicked[1] > intervals[i][0]){
                count++; //overlap detected 
            }
            else{
                lastPicked=intervals[i]; //no overlap ,pick the current one and update the
                // value of lastPicked
            }
        }
        return count;

    }
};