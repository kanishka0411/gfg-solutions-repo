// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int n=arr.size();
        int ceil=-1;
        int st=0;
        int end=n-1;
        
        while(st<=end){
            int mid=(st+end)/2;
            if(arr[mid]>=x){
                ceil=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ceil;
        
    }
};