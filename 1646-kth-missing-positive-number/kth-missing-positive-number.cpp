class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0,h=arr.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            int missing=arr[mid]-(mid+1); //this will be the missing number upto a particular index
            if(missing<k) l=mid+1;
            else h=mid-1;
        }
        //initially low is less than the high but when the loop ends low is greater than the high that is high < low 
        //represents opposite polarity

        //formula for the missing number from the high point after the loop

        //what is more number required that is (k-missing) and missing is arr[high]-(high+1) 

        //answer is arr[high]+more

        // int more = k-(  arr[h]-(h+1)  );
        //answer = arr[h] + k-(  arr[h]-(h+1)  ) becomes
        //answer = k+h+1 or low + k
        return k+h+1 ;
    }
};