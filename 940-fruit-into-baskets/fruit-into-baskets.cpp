class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if (fruits.size() == 1) return 1;
        
        queue<int> q;
        unordered_map<int, int> count;
        int ans = 0;

        for (int fruit : fruits) {
            q.push(fruit);
            count[fruit]++;
            
            // If we have more than 2 types of fruits, reduce the window from the front
            while (count.size() > 2) {
                int front = q.front();
                q.pop();
                count[front]--;
                if (count[front] == 0) {
                    count.erase(front);
                }
            }

            // Update the answer with the current window size
            ans = max(ans, (int)q.size());
        }

        return ans;
    }
};
