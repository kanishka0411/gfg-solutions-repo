//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        
        //----------------------------Brute------------------------------
        // int n=a.size();
        // int m=b.size();
        // vector<int>merged;
        // int i=0, j=0;
        // while(i<n && j<m){
        //     if(a[i]<b[j]) merged.push_back(a[i++]);
        //     else merged.push_back(b[j++]);
            
        // }
        // while(i<n) merged.push_back(a[i++]);
        // while(j<m) merged.push_back(b[j++]);
        // return merged[k-1];
        
        //------------------------------Better-----------------------------
        int n1=a.size();
        int n2=b.size();
        int n=n1+n2;
        int ind=k-1;
        int ind1el=-1;
        int count=0;
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(a[i]<b[j]){
                if(count==ind) ind1el=a[i];
                count++;
                i++;
            }else{
                if(count==ind) ind1el=b[j];
                count++;
                j++;
            }
        }
        
        while(i<n1){
            if(count==ind) ind1el=a[i];
            count++;
            i++;
        }
        
        while(j<n2){
            if(count==ind) ind1el=b[j];
            count++;
            j++;
        }
        
        return ind1el;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends