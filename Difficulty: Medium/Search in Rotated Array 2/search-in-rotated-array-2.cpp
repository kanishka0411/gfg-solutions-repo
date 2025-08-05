class Solution {
  public:
    bool search(vector<int>& arr, int key) {
        int n=arr.size();
        int st=0;
        int end=n-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(arr[mid]==key) return true;
            while(arr[st]==arr[mid] && st<mid) st++;
            while(arr[end]==arr[mid] && end>mid) end--;
            
            if(arr[0]<=arr[mid]){
                if(arr[st]<=key && key<arr[mid]){
                    end=mid-1;
                }else{
                    st=mid+1;
                }
            }else{
                if(arr[mid]<key && arr[end]>=key){
                    st=mid+1;
                }else{
                    end=mid-1;
                }
            }
            
            
        }
        return false;
        
    }
};