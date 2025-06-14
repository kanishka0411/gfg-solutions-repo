// User function Template for C++

class Solution {
  public:
    int xoro(int n){
        if(n%4==1) return 1;
        if(n%4==2) return n+1;
        if(n%4==3) return 0;
        return n;
    }
    int findXOR(int l, int r) {
        return xoro(l-1)^xoro(r);
    }
};