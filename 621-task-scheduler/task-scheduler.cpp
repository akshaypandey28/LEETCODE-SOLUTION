class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        int max_f=0; //max frequency of elements 
        for(int i=0; i<tasks.size(); i++) m[tasks[i]]++;

        priority_queue<int> pq;
        for(auto ele:m) pq.push(ele.second);
        int time=0;
        while(pq.empty()!=1){
            vector<int> temp;
            for(int i=1; i<=n+1; i++){
                if(pq.empty()!=1){
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(int ele:temp){
                if(ele>0) pq.push(ele);
            }

            if(pq.empty()) time+=temp.size();
            else time+=n+1;

            
        }
        return time;
    }
};