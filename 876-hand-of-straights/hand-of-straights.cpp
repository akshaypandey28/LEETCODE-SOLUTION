#define pp pair<int,int>
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        if(hand.size()%k!=0) return false;
        unordered_map<int,int> m;
        for(int i=0; i<hand.size(); i++) m[hand[i]]++;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        for(auto ele:m) pq.push({ele.first,ele.second});

        while(pq.empty()!=1){
            vector<pp> temp;
            int n=k-1;
            pp ele=pq.top();
            pq.pop();
            if((ele.second-1)!=0) temp.push_back({ele.first,ele.second-1});
            
            while(n>0 and pq.empty()!=1 and ele.first+1==pq.top().first){
                ele=pq.top();
                pq.pop();
                if((ele.second-1)!=0) temp.push_back({ele.first,ele.second-1});
                n--;
            }
            if(n!=0) return false;
            for(auto el:temp) pq.push({el.first,el.second});
        }
        return true;
    }
};