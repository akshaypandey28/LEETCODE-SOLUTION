#define pp pair<int,int>
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score=0;
        int n=nums.size();
        vector<bool> marked(n,false);
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        for(int i=0; i<n; i++) pq.push({nums[i],i});
        while(pq.empty()!=1){
            pp curr=pq.top();
            pq.pop(); //log(n)
            int idx=curr.second;

            if(marked[idx]==false){
                marked[idx]=true;
                score+=curr.first;
                if(idx-1>=0 and marked[idx-1]==false) marked[idx-1]=true;
                if(idx+1<n and marked[idx+1]==false) marked[idx+1]=true;
            }
        }
        return score;
    }
};