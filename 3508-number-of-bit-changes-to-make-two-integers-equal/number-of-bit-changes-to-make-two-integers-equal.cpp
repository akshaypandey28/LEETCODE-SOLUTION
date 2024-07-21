class Solution {
public:
    int minChanges(int n, int k) {
        if(k==n) return 0;
        
        int count=0;
        while(n>0){
            if(n%2==1 and k%2==0) count++;
            else if(n%2==0 and k%2==1) return -1;
            k/=2;
            n/=2;
        }
        if(k>0) return -1;
        return count;
    }
};