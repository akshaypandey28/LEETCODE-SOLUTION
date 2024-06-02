class Solution {
public:
    int mySqrt(int x) {
        int l=0,h=x;
        long long ans=1;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(mid*mid<=x) {
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return (int)ans;
    }
};