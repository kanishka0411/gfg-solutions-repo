class Solution {
  public:
    double squareRoot(int n, int p) {
        if(n==0) return 0;
        int st=1;
        int end=n;
        while(st<=end){
            long long mid=st+(end-st)/2;
            long long val=1LL*mid*mid;
            if(val<=n){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        
        double ans=end;
        double inc=0.1;
        for(int i=0;i<p;i++){
            
            while(ans*ans<=n){
                ans+=inc;
            }
            
            ans-=inc;
            
            inc/=10;
        }
        
        return ans;
    }
};