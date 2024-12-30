class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int count=0; // p is people 
        sort(p.begin(),p.end());
       //try to send the maximum weight first and combine it with minimum weight of the person 
       //if it is possible to send then send it 
       //otherwise maximum weight will be send alone 
        int i=0,j=p.size()-1;
        while(i<=j){
            if(p[i]+p[j]<=limit){
                count++;
                i++;
                j--;
            }
            else{
                j--;
                count++;
            }
        }
        return count;
        
    }
};