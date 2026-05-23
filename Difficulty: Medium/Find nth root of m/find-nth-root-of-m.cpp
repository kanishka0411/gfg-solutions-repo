class Solution {
  public:
    long long func(int i,int n){
        long long ans=1;
        for(int j=1;j<=n;j++){
            ans*=i;
        }
        return ans;
    }
    int nthRoot(int n, int m) {
        if(m==0) return 0;
       for(int i=1;i<=m;i++){
           if(func(i,n)==m){
               return i;
           }
       } 
       return -1;
    }
};