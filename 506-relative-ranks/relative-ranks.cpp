#define pp pair<int,int>
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pp> pq;
        vector<string> ans(score.size()); 
        for(int i=0; i<score.size(); i++) pq.push({score[i],i});
        ans[pq.top().second]="Gold Medal";
        pq.pop();
        if(pq.empty()!=1) {
            ans[pq.top().second]="Silver Medal";
            pq.pop();
        }
        if(pq.empty()!=1) {
            ans[pq.top().second]="Bronze Medal";
            pq.pop();
        }
        int rank=4;
        while(pq.empty()!=1){
            ans[pq.top().second]=to_string(rank);
            rank++;
            pq.pop();
        }
        return ans;
    }
};