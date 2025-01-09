class Solution {
public:
    int countOdds(int low, int high) {
        //find total no. of odd number till 1 to low-1 
        //and till 1 to high

        int for_low=low/2; //till low -1 dry run for surity
        int for_high=(high+1)/2;

        //or other ways
        //if( (low-1)%2==0 ) for_low=(low-1)/2;
        //else for_low=(low-1)/2 + 1;
        //same for for_high

        return for_high-for_low;
    }
};