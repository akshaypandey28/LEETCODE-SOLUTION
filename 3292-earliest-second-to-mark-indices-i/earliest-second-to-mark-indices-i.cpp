class Solution {
public:
    bool possible(vector<int>& nums, vector<int>& changeIndices,int mid,long long int sum){
        int n=nums.size();
        //here mid actually represents the time in seconds
        if(mid+1<n) return false;
        if(mid+1< (nums.size()+sum)) return false;
        set<int> s;
        int count1=0; //iska use kitna decrement krna hai nums ke value ke according 
        //mtlb jb bhi koi nums ka index visit hai to us particular index pr jo value hoga wo count1 me already
        //hoga to usko decrement krne ke liye 1 step lgega hi jo count1 me subtract hoga
        //count1=count1-1;



        int count2=0; //ye count krta hai ki kitne index abhi tk visit hue changeIndices ki help se 
        //nums ka visit mark kr pa rhe hai because changeIndices me nums ke index store hai bs changeIndices 
        //sbhi elements ko -1 krna hai tbhi actual index milega nums ke liye
        //let's suppose changeIndices ka ek element 4 hai and nums ka size 4 hai to nums ka last index 
        //3 hoga iske liye 4 se -1 krna pdega
        for(int i=mid; i>=0; i--){
            if(s.count(changeIndices[i]-1)!=1){
                s.insert(changeIndices[i]-1);
                count2++;
                count1+=nums[changeIndices[i]-1];
            }
            else {
                if(count1>0) count1--;
            }
        }
        //jb ye loop hoga aur agr sb kuch shi se calculate hua hai then in that case count2 == n and count1 ==0
        if(count1==0 and count2==n) return true;
        return false;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n=nums.size();
        int m=changeIndices.size();
        int lo=0,hi=m-1;
        long long int sum=0;
        int ans=-1;
        for(int i=0; i<n; i++) sum+=nums[i];
        while(lo<=hi){
            int mid=lo + (hi-lo)/2;
            if(possible(nums,changeIndices,mid,sum)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        if(ans>=0) return ans+1;
        return ans;
    }
};