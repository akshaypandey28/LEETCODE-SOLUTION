//Approach-1 (Using prefixMax and SuffixMin)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixMax(begin(arr), end(arr));
        vector<int> suffixMin(begin(arr), end(arr));

        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], prefixMax[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], suffixMin[i]);
        }

        //concept => i ke phle ka max and i se bad ka min means 
        //i ke phle ka max means (i-1) idx
        //i se bad ka min means i idx
        int chunksCount = 0;
        for (int i = 0; i < n; i++) {
            int pehleKaMax = i > 0 ? prefixMax[i - 1] : -1;
            int baadKaMin  = suffixMin[i];
            
            if(pehleKaMax < baadKaMin) {
                chunksCount++;
            }
        }
        return chunksCount;
    }
};

/* 
//Approach-2 (Using cumulative Sum)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int cumSum    = 0;
        int normalSum = 0;

        int chunksCount = 0;
        for(int i = 0; i < n; i++) {
            cumSum += arr[i];
            normalSum += i;

            if(cumSum == normalSum) {
                chunksCount++;
            }
        }

        return chunksCount;
    }
};
*/

/* 
//Approach-2 (Using max check)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxTillNow = -1;

        int chunksCount = 0;
        for(int i = 0; i < n; i++) {
            maxTillNow = max(maxTillNow, arr[i]);

            if(maxTillNow == i) {
                chunksCount++;
            }
        }

        return chunksCount;
    }
};
*/