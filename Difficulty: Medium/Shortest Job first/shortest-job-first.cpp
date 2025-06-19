// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(),bt.end());
        int n=bt.size();
        long long waitTime=0;
        long long totalTime=0;
        for(int i=0;i<n;i++){
            waitTime+=totalTime;
            totalTime+=bt[i];
        }
        return waitTime/n;
        
    }
};