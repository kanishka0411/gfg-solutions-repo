class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n=arr.size();
        int st=0;
        int end=n-1;
        int first=-1;
        int last=-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(arr[mid]==target){
                first=mid;
                end=mid-1;
            }
            else if(arr[mid]>target){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        
        st=0;
        end=n-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(arr[mid]==target){
                last=mid;
                st=mid+1;
            }
            
            else if(arr[mid]<target){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        
        if(first==-1) return 0;
        return last-first+1;
        
    }
};
