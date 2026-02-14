class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        int first=-1;
        int last=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==x){
                first=i;
                break;
            }
            
        }
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]==x){
                last=i;
                break;
            }
        }
        return {first,last};
        
    }
};