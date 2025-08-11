class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n=arr.size();
        long long ori1=(1LL*n*(n+1))/2;
        long long ori2=(1LL*n*(n+1)*(2*n+1))/6;
        long long act=0;
        long long act2=0;
        for(int i=0;i<n;i++){
            act+=arr[i];
            act2+=1LL*arr[i]*arr[i];
        }
        
        long long diff1=act-ori1;
        long long diff2=(act2-ori2)/diff1;
        
        long long ans1=(diff1+diff2)/2;
        long long ans2=ans1-diff1;
        
        return {(int)ans1,(int)ans2};
        
        
    }
};