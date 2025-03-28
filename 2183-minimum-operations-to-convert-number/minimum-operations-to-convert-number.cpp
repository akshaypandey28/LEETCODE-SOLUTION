class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        unordered_set<int> visited;
        queue<int> qu;
        qu.push(start);
        visited.insert(start);
        int level = 0;

        while (!qu.empty()) {
            int size = qu.size();
            for (int i = 0; i < size; i++) {
                int x = qu.front();
                qu.pop();
                if (x == goal) 
                    return level;
                
                // Skip invalid x early.
                if (x < 0 || x > 1000) 
                    continue;

                for (int ele : nums) {
                    int plus = x + ele;
                    int minus = x - ele;
                    int xor_value = x ^ ele;

                    // Check for goal first.
                    if (plus == goal || minus == goal || xor_value == goal) 
                        return level + 1;

                    // Enqueue only valid and unvisited values.
                    if (plus >= 0 && plus <= 1000 && !visited.count(plus)) {
                        qu.push(plus);
                        visited.insert(plus);
                    }
                    if (minus >= 0 && minus <= 1000 && !visited.count(minus)) {
                        qu.push(minus);
                        visited.insert(minus);
                    }
                    if (xor_value >= 0 && xor_value <= 1000 && !visited.count(xor_value)) {
                        qu.push(xor_value);
                        visited.insert(xor_value);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};