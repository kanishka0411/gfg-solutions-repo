class Solution {
  public:
    bool isPalinSent(string &s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(i<j && !isalnum(s[i])){
                i++;
                continue;
            }
            if(i<j && !isalnum(s[j])){
                j--;
                continue;
            }
            
            if(tolower(s[i])!=tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
        
    }
};