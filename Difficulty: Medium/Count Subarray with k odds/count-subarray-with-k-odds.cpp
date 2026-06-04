class Solution {
  public:
    int helper(vector<int>&arr,int k){
        int l=0;
        int r=0;
        int n=arr.size();
        int sum=0;
        int cnt=0;
        while(r<n){
            sum+=arr[r]%2;
            while(sum>k){
                sum-=arr[l]%2;
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int countSubarrays(vector<int>& arr, int k) {
        return helper(arr,k)-helper(arr,k-1);
        
    }
};