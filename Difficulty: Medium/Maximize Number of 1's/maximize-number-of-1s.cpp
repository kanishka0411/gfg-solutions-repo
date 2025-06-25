class Solution {
  public:
    // k is the maximum number of zeros allowed to flip
    int maxOnes(vector<int>& arr, int k) {
        int n=arr.size();
        int maxLen=0;
        int l=0;
        int r=0;
        int count=0;
        while(r<n){
            if(arr[r]==0) count++;
            if(count>k){
                if(arr[l]==0) count--;
                l++;
            }
            if(count<=k){
                int len=r-l+1;
                maxLen=max(len,maxLen);
            }
            r++;
        }
        return maxLen;
        
    }
};
