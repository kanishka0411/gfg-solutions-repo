//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n=arr.size();
        int i=0;
        int j=n-1;
        int count=0;
        while(i<j){
            if(arr[i]+arr[j]==target){
                if(arr[i]==arr[j]){
                    int pair=j-i+1;
                    count+=pair*(pair-1)/2;
                    break;
                }else{
                    int pair_i=1;
                    int pair_j=1;
                    while(i<j-1 && arr[j]==arr[j-1]){
                        j--;
                        pair_j++;
                    }
                    
                    while(i+1<j && arr[i]==arr[i+1]){
                        i++;
                        pair_i++;
                    }
                    count+=pair_i*pair_j;
                    i++;
                    j--;
                }
            }else if(arr[i]+arr[j]>target){
                j--;
            }else{
                i++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends