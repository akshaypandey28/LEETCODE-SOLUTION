class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p(stones.begin(),stones.end());
        while(p.size()>1){
            int first=p.top();
            p.pop();
            int second=p.top();
            p.pop();
            if(first!=second) p.push(abs(second-first));
        }
        if(p.size()==0) return 0;
        return p.top();
    }
};