class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        int first=-1;
        int last=-1;
        int st=0;
        int end=arr.size()-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(arr[mid]==x){
                first=mid;
                end=mid-1;
            }
            if(arr[mid]>=x) end=mid-1;
            else st=mid+1;
        }
        
        st=0;
        end=arr.size()-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(arr[mid]==x){
                last=mid;
                st=mid+1;
            }
            if(arr[mid]<=x) st=mid+1;
            else end=mid-1;
            
            
        }
        return {first,last};
        
    }
};