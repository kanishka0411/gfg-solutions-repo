class Solution {
  public:
    bool isPrime(int n) {
        bool prime=true;
        if(n==1) return false;
        if(n==2) return true;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                prime=false;
                break;
            }
        }
        if(prime) return true;
        return false;
        
    }
};
