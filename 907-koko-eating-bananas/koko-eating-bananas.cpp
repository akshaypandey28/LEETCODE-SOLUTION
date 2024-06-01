class Solution {
public:
    int maxi(vector<int> v){
       int ans = INT_MIN;
        for(int i = 0; i < v.size(); i++){
            ans = max(ans, v[i]);
        }
        return ans;
    }
    long long calc(vector<int>& piles, int k) {
    long long total = 0;
    for (int i = 0; i < piles.size(); i++) {
        total += ceil((double)piles[i] / k);
    }
    return total;
}
    int minEatingSpeed(vector<int>& piles, int hours) {
        int l=1,h=maxi(piles); //represents k range that is k bananas per hour
        int ans=h;
        while(l<=h){
           int mid = l + (h - l) / 2;
            long long kVal=calc(piles,mid);
            if(kVal<=hours) { //ho skta hai kVal=5 aya hai but 4 might be our answer that's why right side discarded
                h=mid-1;
                ans=min(ans,mid);
            }
            else l=mid+1; //          
        }
        return l;
    }
};