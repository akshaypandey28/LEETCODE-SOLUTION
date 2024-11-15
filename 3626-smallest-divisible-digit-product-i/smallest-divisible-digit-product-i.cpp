class Solution {
public:
    int prod(int x){
        int ans=1; 
        while(x>0){
            ans*=x%10;
            x/=10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        for(int i=n; i<=n+10; i++){
            if(prod(i)%t==0) return i;
        }
        return 0;
    }
};