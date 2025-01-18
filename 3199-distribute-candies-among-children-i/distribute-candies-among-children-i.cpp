class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0;

        for (int i = 0; i <= min(n, limit); ++i) { //candies given to first student
            for (int j = 0; j <= min(n - i, limit); ++j) { //candies given to second student
                int k = n - i - j; ////candies given to third student
                if (k <= limit) ans ++;
            }
        }

        return ans;
    }
};