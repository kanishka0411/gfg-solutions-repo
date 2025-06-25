
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int>ans;
        int res=1;
        ans.push_back(res);
        
        for(int i=1;i<n;i++){
            res*=n-i;
            res=res/i;
            ans.push_back(res);
        }
        return ans;
        
        
    }
};
