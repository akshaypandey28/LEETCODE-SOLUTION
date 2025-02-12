class Solution{
public:
    //dry run this code
    long long minSumSquareDiff(vector<int>& arr1, vector<int>& arr2, int k1, int k2){
        int n = arr1.size(), k = k1 + k2, diff=0, maxDiff=0;

        unordered_map<int,int> freq;
        for(int i=0; i<n; i++){
            diff = abs(arr1[i] - arr2[i]);
            freq[diff]++;
            maxDiff = max(diff, maxDiff);
        }
        
        while(maxDiff > 0 && k > 0){
            if(freq.count(maxDiff)){
                int mn = min(k, freq[maxDiff]);
                k -= mn;
                freq[maxDiff] -= mn;
                freq[maxDiff-1] += mn; //dry run for this line
            }

            maxDiff--;
        }

        long long ans = 0;
        for(auto ele:freq)
            ans += (long long)ele.first * ele.first * ele.second;

        return ans;
    }
};