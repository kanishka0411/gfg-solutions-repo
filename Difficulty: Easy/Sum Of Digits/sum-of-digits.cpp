class Solution {
  public:
    int sumOfDigits(int n) {
        int sum=0;
        while(n>0){
            int r=n%10;
            sum+=r;
            n=n/10;
        }
        return sum;
        
    }
};