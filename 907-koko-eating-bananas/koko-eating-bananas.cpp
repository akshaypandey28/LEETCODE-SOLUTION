class Solution {
public:
    int maxi(vector<int> v){
        int ans=v[0];
        for(int i=1; i<v.size(); i++) {
            if(v[i]>ans) ans=v[i];
        }
        return ans;
    }
    long long calc(vector<int> v,int k){ //k bananas per hour
        long long totalH=0;
        for(int i=0; i<v.size(); i++){
            totalH+=ceil((double)v[i]/(double)k);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int hours) {
        int l=1,h=maxi(piles); //represents k range that is k bananas per hour
        while(l<=h){
            int mid=(l+h)/2;
            long long kVal=calc(piles,mid);
            if(kVal<=hours) h=mid-1; //ho skta hai kVal=5 aya hai but 4 might be our answer that's why right side discarded
            else l=mid+1; //          
        }
        return l;
    }
};