class Solution {
  public:
    int largest(vector<int> &arr) {
        int maxSum=arr[0];
        for(int i=0;i<arr.size();i++){
            maxSum=max(maxSum,arr[i]);
        }
        
        return maxSum;
        
    }
};
