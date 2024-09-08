class Solution {
public:
    bool isPowerOfThree(int n) {
        int maxi=pow(3,19);
        return n > 0 &&  maxi% n == 0;
    }
};
