class Solution {
  public:
    int merge(vector<int>&arr,int low,int mid,int high){
        int i=low;
        int j=mid+1;
        int cnt=0;
        vector<int>temp;
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                temp.push_back(arr[j]);
                cnt+=mid-i+1;
                j++;
            }
        }
        
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j<=high){
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
        
        return cnt;
    }
    int ms(vector<int>&arr,int low,int high){
        int cnt=0;
        if(low==high) return cnt;
        int mid=(low+high)/2;
        cnt+=ms(arr,low,mid);
        cnt+=ms(arr,mid+1,high);
        cnt+=merge(arr,low,mid,high);
        
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        int n=arr.size();
        return ms(arr,0,n-1);
        
    }
};