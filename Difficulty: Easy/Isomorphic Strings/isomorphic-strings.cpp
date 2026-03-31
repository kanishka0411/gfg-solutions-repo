class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        int n=s1.size();
        int s[256]={0};
        int t[256]={0};
        for(int i=0;i<n;i++){
            if((s[s1[i]]!=0 || t[s2[i]]!=0) && (s[s1[i]]!=s2[i]+1 || t[s2[i]]!=s1[i]+1)){
                return false;
            }
            
            s[s1[i]]=s2[i]+1;
            t[s2[i]]=s1[i]+1;
        }
        
        return true;
        
    }
};