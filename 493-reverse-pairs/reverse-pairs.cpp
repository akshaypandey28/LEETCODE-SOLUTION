class Solution {
public:
    

    void merge(vector<int> &arr, int low, int mid,int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
    int countPairs(vector<int>& a,int l,int h,int mid){
        int right=mid+1;
        int count=0;
        for(int i=l; i<=mid; i++){
            while(right<=h and a[i] > (long long) 2 * (long long)a[right]) right++;
            count+=right-(mid+1);
        }
        return count;
    }
    int mergeSort(vector<int>& a,int l,int h){
        int count=0;
        if(l>=h) return count;
        int mid = (l + h) / 2 ;
        count+=mergeSort(a,l,mid);
        count+=mergeSort(a,mid+1,h);
        count+=countPairs(a,l,h,mid);
        merge(a,l,mid,h);
        return count;
    }
    int reversePairs(vector<int>& a) {
        int n=a.size();
        return mergeSort(a,0,n-1);
        //return count;
    }
};