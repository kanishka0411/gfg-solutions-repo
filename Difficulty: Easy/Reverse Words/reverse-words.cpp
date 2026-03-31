class Solution {
  public:
    string reverseWords(string &s) {
        stack<string>st;
        stringstream ss(s);
        string word;
        
        while(getline(ss,word,'.')){
            if(word!=""){
               st.push(word); 
            }
            
        }
        string res="";
        
        while(!st.empty()){
            res+=st.top();
            st.pop();
            if(!st.empty()){
                res+=".";
            }
        }
        return res;
        
    }
};