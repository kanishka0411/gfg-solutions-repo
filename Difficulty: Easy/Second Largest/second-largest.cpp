class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int maxi=-1;
        int smax=-1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>maxi){
                smax=maxi;
                maxi=max(maxi,arr[i]);
            }else if(arr[i]>smax && arr[i]!=maxi){
                smax=arr[i];
            }
        }
        return smax;
        
    }
};