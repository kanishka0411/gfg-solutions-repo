class Solution {
  public:
    bool checkKthBit(int n, int k) {
        if((n>>k & 1)==0){
            return false;
        }
            return true;
        
        
    }
};