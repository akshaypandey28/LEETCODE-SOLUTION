class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        vector<int> maxi(n,0); //gives the maximum element index of each index element after index to n for num
        maxi[n-1]=n-1;
        int maxi_num=s[n-1]-'0';
        int maxi_num_idx=n-1;
        for(int i=n-2; i>=0; i--){
            int a=s[i]-'0';
            if(a<=maxi_num) maxi[i]=maxi_num_idx;

            else{
                maxi[i]=i;
                maxi_num_idx=i;
                maxi_num=a;
            }
        }
        for(int i=0;i<n; i++){
            int a=s[i]-'0';
            int idx=maxi[i];
            int b=s[idx]-'0';
            if(a!=b){
                swap(s[i],s[idx]);
                break;
            }
        }
        int ans=stoi(s);
        return ans;
    }
};