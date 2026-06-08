class Solution {
  public:
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int>dp(n+1,-1);
        dp[0]=0;
        for(int i=1;i<n;i++){
            int j1=dp[i-1]+abs(height[i]-height[i-1]);
            int j2=INT_MAX;
            if(i>1){
                j2=dp[i-2]+abs(height[i]-height[i-2]);
            }
            dp[i]=min(j1,j2);
            
        }
        return dp[n-1];
        
    }
};