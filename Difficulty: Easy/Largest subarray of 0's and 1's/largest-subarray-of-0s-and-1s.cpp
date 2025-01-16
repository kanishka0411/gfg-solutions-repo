//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n=arr.size();
        unordered_map<int,int>mpp;
        int preSum=0;
        int res=0;
        for(int i=0;i<n;i++){
            preSum+=(arr[i]==0)?-1:1;
            if(preSum==0){
                res=i+1;
            }
            if(mpp.find(preSum)!=mpp.end()){
                res=max(res,i-mpp[preSum]);
            }else{
                mpp[preSum]=i;
            }
            
            
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends