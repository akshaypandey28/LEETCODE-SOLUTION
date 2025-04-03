class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        unordered_set<int> visited;
        queue<int> qu;
        qu.push(start);
        visited.insert(start);
        while(qu.empty()!=1){
            int index=qu.front();
            qu.pop();
            int left_jump=index-arr[index];
            int right_jump=index+arr[index];
            if(left_jump>=0 and arr[left_jump]==0) return true;
            if(right_jump<n and arr[right_jump]==0) return true;

            if(left_jump>=0 and visited.find(left_jump)==visited.end()) {
                qu.push(left_jump);
                visited.insert(left_jump);
            }

            if(right_jump<n and visited.find(right_jump)==visited.end()) {
                qu.push(right_jump);
                visited.insert(right_jump);
            }
        }
        return false;
    }
};