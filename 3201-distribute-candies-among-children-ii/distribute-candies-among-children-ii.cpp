class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        //for first children
        int firstChildrenMin=max(0, n - 2*limit);
        int firstChildrenMax=min(limit,n);

        for(int i=firstChildrenMin; i<=firstChildrenMax; i++){
            //for second children
            int secondChildrenMin=max(0, n-i - limit); //n-i is remaining candies after giving 
            //to first children
            int secondChildrenMax=min(limit,n-i);

            //no. of ways to provide candies to second children is
            //secondChildrenMax - secondChildrenMin + 1 and this contribute for the answer part
            int no_of_ways=secondChildrenMax-secondChildrenMin+1;
            ans+=no_of_ways;
        }
        return ans;
    }
};