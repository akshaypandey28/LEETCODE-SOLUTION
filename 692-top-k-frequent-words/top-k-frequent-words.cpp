#define pp pair<int, string>

class cmp {
public:
    bool operator()(const pp& p1, const pp& p2) {
        // Compare based on the lexicographical order
        if (p1.first == p2.first) {
            return p1.second < p2.second;
        }
        // compare based on the integer value min heap
        return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for (int i = 0; i < words.size(); i++) m[words[i]]++;
        
        priority_queue<pp, vector<pp>, cmp> pq;
        for (auto ele : m) {
            pq.push({ele.second, ele.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
