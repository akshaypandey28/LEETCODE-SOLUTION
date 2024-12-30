class Solution {
public:
    int f(int startValue, int target) {
        if (startValue <= target) 
            return target - startValue; // If startValue is lesser, subtract the difference.
        
        if (startValue % 2 == 0)
            return 1 + f(startValue/2, target); // If startValue is even, divide it by 2.
        else
            return 1 + f(startValue+1, target); // If startValue is odd, increment it.
    }
    
    int brokenCalc(int startValue, int target) {
        //instead of going from startValue to target , go for reverse target to startValue
        //(*2,-1) changes to (/2,+1) because *2 can cause integer overflow
        return f(target, startValue);
    }
};
