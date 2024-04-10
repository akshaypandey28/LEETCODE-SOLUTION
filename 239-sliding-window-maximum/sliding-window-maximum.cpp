class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int> dq;    
    vector<int> res;
    //i am maintaining the maximum at deque front and after that elements are in decreasing order
    for(int i=0; i<k; i++){
        while(dq.empty()!=1 && a[dq.back()]<a[i]) dq.pop_back();  

        dq.push_back(i);
    }
    res.push_back( a[dq.front()] );
    for(int i=k; i<a.size(); i++){
        int curr=a[i];

        if(dq.front()==i-k)  dq.pop_front(); 

        while(dq.empty()!=1 && a[dq.back()]<a[i])  dq.pop_back();

        dq.push_back(i);

        res.push_back( a[dq.front()] ); 
    }
    return res;
    }
};