class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int result = guess(mid);  // Call guess only once and store result
            if (result == 0) return mid;
            if (result == 1) l = mid + 1;  // Move the left pointer up
            else r = mid - 1;  // Move the right pointer down
        }
        return -1;
    }
};
