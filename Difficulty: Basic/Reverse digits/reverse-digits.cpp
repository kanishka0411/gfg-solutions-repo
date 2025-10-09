class Solution {
  public:
    int reverseDigits(int n) {
        int num=n;
        int sum=0;
        while(num>0){
            sum*=10;
            sum+=num%10;
            num/=10;
        }
        return sum;
        
    }
};