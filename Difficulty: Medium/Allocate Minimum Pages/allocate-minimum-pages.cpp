//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      
    int count(vector<int>&arr,int pages){
        int n=arr.size();
        int student=1;
        int pagesCount=0;
        for(int i=0;i<n;i++){
            if(pagesCount+arr[i]<=pages){
                pagesCount+=arr[i];
            }else{
                student++;
                pagesCount=arr[i];
            }
        }
        
        return student;
    }
    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(k>n) return -1;
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        // for(int pages=low;pages<=high;pages++){
        //     if(count(arr,pages)==k){
        //         return pages;
        //     }
        // }
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int student=count(arr,mid);
            if(student>k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        
        return low;
     
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends