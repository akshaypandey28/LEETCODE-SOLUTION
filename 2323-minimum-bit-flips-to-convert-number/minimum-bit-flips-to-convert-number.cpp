class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flipped=start^goal; //this gives the point where bit has to be flipped
        //if the binary of start and goal differ then xor flip the differ bits and makes it 1 and same bit has to 
        //be rejected because there is need to flipped them and it cause 0 for same bits
        //overall different bits gets changed into 1 and same into 0
        //and flipped contains 1 and 0 in binary form and the no. of ones of in flipped gives the no. of bits 
        //has to be flipped i.e answer
        int count=0;
        while(flipped>0){
            if(flipped%2==1) count++;
            flipped/=2;
        }
        return count;
    }
};