class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n=arr.size();
        int low=0;
        int ans=INT_MAX;
        int index=-1;
        int end=n-1;
        while(low<=end){
            int mid=(low+end)/2;
            if(arr[low]<=arr[end]){
                if(arr[low]<ans){
                    ans=min(ans,arr[low]);
                    index=low;
                }
                break;
            }
            if(arr[low]<=arr[mid]){
                if(arr[low]<ans){
                    ans=min(ans,arr[low]);
                    index=low;
                }
                low=mid+1;
            }else{
                if(arr[mid]<=ans){
                    ans=min(ans,arr[mid]);
                    index=mid;
                }
                end=mid-1;
            }
        }
        return index;
        
    }
};
