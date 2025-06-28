
class Solution {
  public:
    bool isBalanced(string& k) {
       int n=k.size();
       stack<char>st;
       for(int i=0;i<n;i++){
           if(k[i]=='(' || k[i]=='{' || k[i]=='['){
               st.push(k[i]);
           }else if(!st.empty() &&((st.top()=='(' && k[i]==')') || (st.top()=='{' && k[i]=='}') || (st.top()=='[' && k[i]==']'))){
               st.pop();
           }else{
               return false;
           }
       }
       return st.empty();
    }
};