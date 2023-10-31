class Solution {
public:
    int sum(int n){
        int ans=0;
        while(n>0){
            ans+=pow(n%10,2);
            n=n/10;
        }
        return ans;
    }
    bool isHappy(int N) {
        unordered_set<int> visited;
        visited.insert(N);
        int n=N;
        while(n!=1){
            int ans=sum(n);
            
            if(ans==1){
                return 1;
            }
            else if(visited.count(ans)==1) return 0;
            else{
                n=ans;
                visited.insert(n);
            }
        }
        return 1;
    }
};