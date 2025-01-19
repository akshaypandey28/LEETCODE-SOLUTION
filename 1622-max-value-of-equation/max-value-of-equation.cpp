
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        int res = INT_MIN;

        for (vector<int> point : points) {
            while (!pq.empty() && point[0] - pq.top().second > k) {
                pq.pop();
            }
            if (!pq.empty()) {
                res = max(res, pq.top().first + point[0] + point[1]);
            }
            pq.push({point[1] - point[0], point[0]});
        }
        return res;
    }
};