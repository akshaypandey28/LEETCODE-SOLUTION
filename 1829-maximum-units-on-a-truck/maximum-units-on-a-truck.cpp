class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans=0;
        for(vector<int> ele:boxTypes){
            int minBox=min(ele[0],truckSize);
            truckSize-=minBox;
            ans+=minBox*ele[1];
            if(truckSize<=0) break;
        }
        return ans;
    }
};