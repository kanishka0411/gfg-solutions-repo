class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        int nse;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }else{
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        return ans;
        
    }
};