class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        while(n>1){ //for pow(4,0) that's why 1
            if(n%4) return false;
            n/=4;
        }
        return true;
    }
};