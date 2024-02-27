class Solution {
public:
    bool isPossible(vector<int>& nums,vector<int> &changeIndices,int time,int sum){
        int n=nums.size(); 

        // dekho jitna time hai mere pass
        // agr vo mere number of index ( nums ke )
        // usse kam hai to knha se possible ho payega

        // arey dekho 4 second yani 4 element 
        // aur nums me hai 10 ele kya nums ka har index mark ho payega
        // nhi n simple ...\U0001f60a
        if(time<n) return false;

        // ye wala case explain kiya tha maine
        // ki minimum time (sum + n) to hona hi chaiye
        // hmare pass, samjhe
        if(time<sum+nums.size()) return false;

        // ye ye btayega ki n tak ki index mark hui ya nhi
        vector<int> vis(n,0);

        // ye count karega decrement
        int cnt=0;
        // ye count krega kitni index vis hui
        // n tak hui ya nhi
        int cnt2=0;


        // dekho aakhir maine pichche se kyu traverse kiya
        // kyuki pehle mujhe decremnet krna hai
        // phir mark krna hia
        // to har value yani 1 to n,  ki last
        // index save krenge taki
        // aage ke elemnts ka use 
        // decrement ke liye use kr sku

        // test case => 
        // nums = 0 2 3 0
        // chnage => 1 2 4 1 3 3 3 3 3 3 2 1

        // agr aage se check kroge to 9 second me kaam hota dikhega 
        // jo ki galat hai,10 second lagega ye shi hai
        for(int i=time-1;i>=0;i--){

            // agr index visited nhi hai to visit kr do
            if(!vis[changeIndices[i]-1])
            {
                vis[changeIndices[i]-1]=1;
                // ye bta rha 1 to n me 
                // kitne index visit huye
                cnt2+=1;

                // us index ki value decrement krne ke liye
                // itne opr ki jarurat to padegi hi
                // yani value 0 to karni hi hai n
                // tabhi mark kar payege

                // thoda complex lag skta hai, doubt huaa hai to
                // comment kr do
                cnt+=(nums[changeIndices[i]-1]);
            }
            else
            {
                if(cnt>0)
                {   // decrement kr rhe 
                    cnt-=1;
                    if(cnt<0)cnt=0;
                }
            }
            
        }   

        // agr decrement bhi ho gya and all visit then
        // possible hai
        if(cnt==0&&cnt2==n)return 1;
        return false;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {

        // ye to variables hai, esme kya btau
        // tum hi bta do \U0001f972
        int n=changeIndices.size();
        int s=1;
        int e=n;
        int mid=0;

        // kuchch nhi hoga to -1, to hoga hi \U0001f60a
        int ans=-1;

        // dekho minimum wala case sochate hai 
        // ki minimum kitna time chaiye hoga 
        // pure nums ko visit karne ke liye

        // espe dhyan dena

        // sum(nums ke har element ka) + nums ka size
        // itna to krna hi padega

        // kyu abhi bhai, aisa kyu
        // dekho...
        // 1 se decrement krenge yani utne number
        // hone chaiye tabhi sabko decrement nikal payenge
        // and mark karne ke liye n elements chaiye honge jo ki
        // 1 to n index ko cover kar rhe ho
        long long int sum=0; 
        for(auto it:nums) sum+=it;

        // simple binary search template
        while(s<=e){
            mid=s+(e-s)/2;

            // ye check krega, ki es mid time me 
            // possible hai ya nhi ⚡⚡⚡⚡
            if(isPossible(nums,changeIndices,mid,sum)){
                ans=mid;

                // earlist btana hai yani jis point pe
                // ans mila uske pichche jake dekhenge possible 
                // hai ya nhi
                e=mid-1;
            }
            else{
                // agr us point pe possible nhi hai to
                // aage dekhenge
                s=mid+1;
            }
        }

        // ans return kiya

        // I hope har line ke Why ke sath, samjh aaya hoga
        // doubt hai to comment kr do..\U0001f60a❤️
        return ans;
    }
};