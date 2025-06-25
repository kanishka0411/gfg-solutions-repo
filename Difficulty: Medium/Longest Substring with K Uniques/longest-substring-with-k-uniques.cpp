// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n=s.size();
        unordered_map<char,int>mpp;
        int maxlen=-1;
        int l=0;
        int r=0;
        while(r<n){
            mpp[s[r]]++;
            if(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            if(mpp.size()==k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
        
    }
};





// for(int i=0;i<n;i++){
            
//         //     for(int j=i;j<n;j++){
//         //         mpp[s[j]]++;
//         //         if(mpp.size()==k){
//         //             maxlen=max(maxlen,j-i+1);
//         //         }else if(mpp.size()>k){
        //             break;
        //         }
        //     }
        // }