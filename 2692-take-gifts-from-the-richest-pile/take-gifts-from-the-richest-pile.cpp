//Approach (Using max-heap)
//T.C : O(n + k*logn)
//S.C : O(n)
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        //Heapify - O(n)
        priority_queue<int> pq(begin(gifts), end(gifts)); //max-heap

        long long sum = 0;

        while(k--) { //O(k)
            int maxEl = pq.top(); //O(1)
            pq.pop(); //O(log(n))

            int remaining = sqrt(maxEl); //Ignoring this time complexity
            pq.push(remaining);//O(log(n))
        }
        while(pq.empty()!=1){
            sum+=pq.top();
            pq.pop();
        }
        return sum;

    }
};