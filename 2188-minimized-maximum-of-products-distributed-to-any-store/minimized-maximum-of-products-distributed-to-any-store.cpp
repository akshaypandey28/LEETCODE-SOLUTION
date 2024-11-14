class Solution {
public:
    bool possibleToDistribute(int x, vector<int> &q, int n) {
        int count = 0;
        for (int i = 0; i < q.size(); i++) count += ceil((double)q[i] / x); // Use floating-point division with ceil
        return count <= n;
    }

    int minimizedMaximum(int n, vector<int>& q) {
        int m = q.size();
        int l = 1;
        int r = *max_element(q.begin(), q.end());
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (possibleToDistribute(mid, q, n)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};