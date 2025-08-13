class Solution {
  public:
  
    int bsearch(int arr[],int target_idx,int k,vector<int>&psum){
        int target=arr[target_idx];
        int l=0;
        int r=target_idx;
        int best_idx=target_idx;
        while(l<=r){
            int mid=l+(r-l)/2;
            long count=(target_idx-mid+1);
            long windowSum=count*target;
            
            long currSum=psum[target_idx]-psum[mid]+arr[mid];
            int ops=windowSum-currSum;
            
            if(ops>k){
                l=mid+1;
            }else{
                best_idx=mid;
                r=mid-1;
            }
            
        }
        
        
        return target_idx-best_idx+1;
    }
    int maxFrequency(int arr[], int n, int k) {
        sort(arr,arr+n);
        vector<int>psum(n,0);
        for(int i=1;i<n;i++){
            psum[i]=psum[i-1]+arr[i];
        }
        int result=0;
        for(int target_idx=0;target_idx<n;target_idx++){
            result=max(result,bsearch(arr,target_idx,k,psum));
        }
        return result;
    }
};