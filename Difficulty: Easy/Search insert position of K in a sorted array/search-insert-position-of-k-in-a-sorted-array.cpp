//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        if(Arr[N-1]<k) return N;
        for(int i=0;i<N;i++){
            if(Arr[i]==k) return i;
            else if(Arr[i]>k) return i;
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends