#define pp pair<long long int,long long int>
bool cmp(pp p1,pp p2){
    return p1.first > p2.first;
}
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pp> v;
        for(int i=0; i<n; i++){
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.begin(),v.end(),cmp); //decreasing order sort on the basis of efficiency
        long long int ts=0;//total sum
        long long int ans=0;
        priority_queue<pp ,vector<pp> ,greater<pp> > pq; // sort on the basis of speed min heap
        for(int i=0; i<n; i++){
            if(pq.size()==k){ //jaise hi equal hoga kisi element ko htna pdega
                ts-=pq.top().first;  //speed
                pq.pop();
            }
            pq.push({v[i].second,v[i].first});
            ts+=v[i].second;
            ans=max(ans,ts*v[i].first); //efficiency minimum hona chahiye
        }
        return ans %(1000000007);
    }
};