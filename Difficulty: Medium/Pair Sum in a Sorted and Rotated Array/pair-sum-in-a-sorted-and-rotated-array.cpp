// User function Template for C++

class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        int n=arr.size();
        int pivot=-1;
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                pivot=i;
            }
        }
        if(pivot==-1){
            pivot=n-1;
        }
        int l=(pivot+1)%n;
        int r=pivot;
        while(l!=r){
            int sum=arr[l]+arr[r];
            if(sum==target) return true;
            if(sum<target){
                l=(l+1)%n;
            }else{
                r=(n+r-1)%n;
            }
        }
        return false;
        
    }
};