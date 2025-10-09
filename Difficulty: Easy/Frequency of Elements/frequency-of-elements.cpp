class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        unordered_map<int,int>mpp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        vector<vector<int>>ans;
        for(auto it:mpp){
            ans.push_back({it.first,it.second});
        }
        return ans;
        
    }
};